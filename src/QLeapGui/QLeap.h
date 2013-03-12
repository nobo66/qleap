/* QLeap.h --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Dec 18 18:35:45 2012 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Mar 13 00:33:06 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 175
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

class QLeap : public QObject, public QTouchDevice
{
    Q_OBJECT

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

public slots:
    void    addTarget(QObject *object);
    void removeTarget(QObject *object);

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
