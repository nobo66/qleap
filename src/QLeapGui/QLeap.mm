/* QLeap.mm --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Thu Jan 10 11:11:08 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Thu Jan 10 13:15:39 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 7
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#include "QLeap.h"

#include <QtWidgets>

#import <Cocoa/Cocoa.h>

void qleap_enable_touch_events(QWidget *widget)
{
    NSView *view = reinterpret_cast<NSView *>(widget->winId());

    [view setAcceptsTouchEvents: YES];

    widget->setAttribute(Qt::WA_AcceptTouchEvents, true);
}
