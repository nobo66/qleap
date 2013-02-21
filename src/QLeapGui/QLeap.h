/* QLeap.h --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Dec 18 18:35:45 2012 (+0100)
 * Version: $Id$
 * Last-Updated: Thu Feb 21 11:33:40 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 151
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#pragma once

#include "QLeapGuiExport"

#include <QtCore>
#include <QtGui>

#include <Leap.h>

// /////////////////////////////////////////////////////////////////
// Helper macros
// /////////////////////////////////////////////////////////////////

#define qLeap QLeap::instance()

// /////////////////////////////////////////////////////////////////
// QLeap
// /////////////////////////////////////////////////////////////////

class QLeapController;
class QLeapListener;
class QLeapPrivate;

class QLeap : public QTouchDevice
{
public:
    static QLeap *instance(void);

#pragma mark -
#pragma mark Elements

    QLeapController *controller(void);
    QLeapListener *listener(void);

#pragma mark -
#pragma mark Touch device information

    QTouchDevice::Capabilities capabilities(void) const;
    QTouchDevice::DeviceType type(void) const;
    QString name(void) const;

#pragma mark -
#pragma mark Target management

    void addTarget(QObject *object);

protected:
     QLeap(void);
    ~QLeap(void);

private:
    QLeapPrivate *d;
};

// /////////////////////////////////////////////////////////////////
// Helper functions
// /////////////////////////////////////////////////////////////////

void qleap_enable_touch_events(QWidget *widget);

QPointF qleap_pointf(const Leap::Vector& position);
Leap::Vector qleap_vector(const QPointF& position);
