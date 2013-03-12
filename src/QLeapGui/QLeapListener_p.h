/* QLeapListener_p.h --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Dec 18 18:11:50 2012 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Mar 12 13:11:39 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 75
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#pragma once

#include <QtCore>
#include <QtGui>

#include <Leap.h>

class QLeapListenerPrivate : public Leap::Listener
{
public:
    QLeapListenerPrivate(void);

public:
    void onInit(const Leap::Controller& controller);
    void onConnect(const Leap::Controller& controller);
    void onDisconnect(const Leap::Controller& controller);
    void onFrame(const Leap::Controller& controller);

public:
    QObjectList targets;

public:
    int curr_touch_count;
    int prev_touch_count;

public:
    QEvent::Type curr_touch_event_type;
    QEvent::Type prev_touch_event_type;
    QEvent::Type curr_mouse_event_type;
    QEvent::Type prev_mouse_event_type;

public:
    Leap::Frame *start;
};
