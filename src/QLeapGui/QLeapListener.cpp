/* QLeapListener.cpp --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Dec 18 17:34:10 2012 (+0100)
 * Version: $Id$
 * Last-Updated: Fri Jan 18 18:18:48 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 1117
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#include "QLeap"
#include "QLeapListener"
#include "QLeapListener_p"
#include "QLeapMapper"

#include <QtCore>
#include <QtDebug>
#include <QtWidgets>

// /////////////////////////////////////////////////////////////////
// QLeapListenerPrivate
// /////////////////////////////////////////////////////////////////

QLeapListenerPrivate::QLeapListenerPrivate(void) : Leap::Listener()
{
    this->prev_event_type = QEvent::None;
    this->curr_event_type = QEvent::None;

    this->prev_touch_count = 0;
    this->curr_touch_count = 0;

    this->start = NULL;
}

void QLeapListenerPrivate::onInit(const Leap::Controller& controller)
{
    Q_UNUSED(controller);
}

void QLeapListenerPrivate::onConnect(const Leap::Controller& controller)
{
    Q_UNUSED(controller);
}

void QLeapListenerPrivate::onDisconnect(const Leap::Controller& controller)
{
    Q_UNUSED(controller);
}

void QLeapListenerPrivate::onFrame(const Leap::Controller& controller)
{
    this->prev_touch_count = this->curr_touch_count;
    this->curr_touch_count = 0;

    this->prev_event_type = this->curr_event_type;
    this->curr_event_type = QEvent::None;

    QList<QTouchEvent::TouchPoint> points;

    const Leap::Screen screen = controller.calibratedScreens()[0];
    const Leap::HandList hands = controller.frame().hands();

    for(int h = 0; h < hands.count(); h++) {
                
        const Leap::FingerList fingers = hands[h].fingers();
        
        for(int f = 0; f < fingers.count(); f++) {
           
            const Leap::Finger finger = fingers[f];

            QTouchEvent::TouchPoint point(finger.id());

            if(this->start) {
                QPointF position = qleap_pointf(screen.intersect(this->start->hands()[h].fingers()[f], true));
                point.setStartPos(QLeapMapper::mapToSpace(position));
                point.setStartScenePos(QLeapMapper::mapToScene(position));
                point.setStartScreenPos(QLeapMapper::mapToScreen(position));
            }

            if(true) {
                QPointF position = qleap_pointf(screen.intersect(finger, true));
                point.setPos(QLeapMapper::mapToSpace(position));
                point.setScenePos(QLeapMapper::mapToScene(position));
                point.setScreenPos(QLeapMapper::mapToScreen(position));
            }

            if(this->prev_event_type == QEvent::TouchBegin || this->prev_event_type == QEvent::TouchUpdate) {
                QPointF position = qleap_pointf(screen.intersect(controller.frame(1).hands()[h].fingers()[f], true));
                point.setLastPos(QLeapMapper::mapToSpace(position));
                point.setLastScenePos(QLeapMapper::mapToScene(position));
                point.setLastScreenPos(QLeapMapper::mapToScreen(position));
            }

            points << point;
        }
    }

    this->curr_touch_count = points.count();

    ( curr_touch_count && !prev_touch_count) ? curr_event_type = QEvent::TouchBegin :
    ( curr_touch_count &&  prev_touch_count) ? curr_event_type = QEvent::TouchUpdate :
    (!curr_touch_count &&  prev_touch_count) ? curr_event_type = QEvent::TouchEnd :
    (!curr_touch_count && !prev_touch_count) ? curr_event_type = QEvent::TouchCancel : curr_event_type = QEvent::None;

    if(curr_event_type == QEvent::TouchUpdate && curr_touch_count && curr_touch_count != prev_touch_count) {
        curr_event_type = QEvent::TouchEnd;
        points.clear();
        curr_touch_count = 0;
    }

    Qt::TouchPointStates states = 0;
    // states |= Qt::TouchPointPressed;
    // states |= Qt::TouchPointMoved;
    // states |= Qt::TouchPointStationary;
    // states |= Qt::TouchPointReleased;

    if((this->curr_event_type == QEvent::TouchEnd || this->curr_event_type == QEvent::TouchCancel) && this->start) {
        delete this->start;
        this->start = NULL;
    }

    if (this->curr_event_type == QEvent::TouchBegin) {
        this->start = new Leap::Frame(controller.frame());
    }

// /////////////////////////////////////////////////////////////////
// Debug pan gesture
// /////////////////////////////////////////////////////////////////
#if 0
    if (this->curr_event_type == QEvent::TouchUpdate && points.count() == 2) {

        QTouchEvent::TouchPoint p1 = points.at(0);
        QTouchEvent::TouchPoint p2 = points.at(1);

        QPointF offset = QPointF(
            p1.pos().x() - p1.startPos().x() + p2.pos().x() - p2.startPos().x(),
            p1.pos().y() - p1.startPos().y() + p2.pos().y() - p2.startPos().y()) / 2;

        if (offset.x() >  10 || offset.y() >  10 || offset.x() < -10 || offset.y() < -10)
            qDebug() << Q_FUNC_INFO << offset << "PanGesture TRIGGERABLE";
        else
            qDebug() << Q_FUNC_INFO << offset << "PanGesture untriggerable";
    }
#endif
// /////////////////////////////////////////////////////////////////


    foreach(QObject *target, this->targets)
        QCoreApplication::postEvent(target, new QTouchEvent(this->curr_event_type, qLeap, Qt::NoModifier, states, points));
}

// /////////////////////////////////////////////////////////////////
// QLeapListener
// /////////////////////////////////////////////////////////////////

QLeapListener::QLeapListener(void) : d(new QLeapListenerPrivate)
{

}

QLeapListener::~QLeapListener(void)
{
    delete d;

    d = NULL;
}

void QLeapListener::addTarget(QObject *target)
{
    if(target && !d->targets.contains(target))
        d->targets << target;
}
