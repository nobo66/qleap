/* QLeap.cpp --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Dec 18 18:37:27 2012 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Mar 13 00:31:27 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 174
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#include "QLeap"
#include "QLeapController"
#include "QLeapListener"

#include <QtCore>
#include <QtGui>
#include <QtWidgets>

// /////////////////////////////////////////////////////////////////
// QLeapPrivate
// /////////////////////////////////////////////////////////////////

class QLeapPrivate
{
public:
    QLeapController *controller;
    QLeapListener *listener;

public:
    static QLeap *leap;
};

QLeap *QLeapPrivate::leap = NULL;

// /////////////////////////////////////////////////////////////////
// QLeap
// /////////////////////////////////////////////////////////////////

QLeap *QLeap::instance(void)
{
    if(!QLeapPrivate::leap)
        QLeapPrivate::leap = new QLeap;
 
    return QLeapPrivate::leap;
}

QLeapController *QLeap::controller(void)
{
    return d->controller;
}

QLeapListener *QLeap::listener(void)
{
    return d->listener;
}

#pragma mark -
#pragma mark Touch device information

QTouchDevice::Capabilities QLeap::capabilities(void) const
{
    return QTouchDevice::Position;
}

QTouchDevice::DeviceType QLeap::type(void) const
{
    return QTouchDevice::TouchScreen;
}

QString QLeap::name(void) const
{
    return "Leap Motion";
}

#pragma mark -
#pragma mark Target management

void QLeap::addTarget(QObject *object)
{
    d->listener->addTarget(object);

    if(QWidget *widget = qobject_cast<QWidget *>(object))
	qleap_enable_touch_events(widget);

    connect(object, SIGNAL(destroyed(QObject *)), this, SLOT(removeTarget(QObject *)));
}

void QLeap::removeTarget(QObject *object)
{
    d->listener->removeTarget(object);
}

QLeap::QLeap(void) : QTouchDevice(), d(new QLeapPrivate)
{
    d->listener = new QLeapListener;
    
    d->controller = new QLeapController;
    d->controller->setListener(d->listener);
}

QLeap::~QLeap(void)
{
    delete d->listener;
    delete d->controller;
    delete d;

    d = NULL;
}

// /////////////////////////////////////////////////////////////////
// Helper functions
// /////////////////////////////////////////////////////////////////

#if !defined(Q_OS_MAC)
void qleap_enable_touch_events(QWidget *widget)
{
    widget->setAttribute(Qt::WA_AcceptTouchEvents, true);
}
#endif
