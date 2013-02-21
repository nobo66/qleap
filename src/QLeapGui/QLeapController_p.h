/* QLeapController_p.h --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Dec 18 18:33:00 2012 (+0100)
 * Version: $Id$
 * Last-Updated: Thu Feb 21 11:48:16 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 28
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#pragma once

#include <QtCore>

#include <Leap.h>

class QLeapListener;

class QLeapControllerPrivate : public Leap::Controller
{
public:
     QLeapControllerPrivate(void);
    ~QLeapControllerPrivate(void);

public:
    void addListener(QLeapListener *listener);

public:
    QList<QLeapListener *> listeners;
};

