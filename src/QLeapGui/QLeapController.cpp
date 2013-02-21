/* QLeapController.cpp --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Dec 18 18:31:39 2012 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Jan  8 10:31:19 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 66
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#include "QLeapController"
#include "QLeapController_p"
#include "QLeapListener"
#include "QLeapListener_p"

// /////////////////////////////////////////////////////////////////
// QLeapControllerPrivate
// /////////////////////////////////////////////////////////////////

QLeapControllerPrivate::QLeapControllerPrivate(void) : Leap::Controller()
{

}

QLeapControllerPrivate::~QLeapControllerPrivate(void)
{
    foreach(QLeapListener *listener, this->listeners)
        Leap::Controller::removeListener(*(listener->d));
}

void QLeapControllerPrivate::addListener(QLeapListener *listener)
{
    Leap::Controller::addListener(*(listener->d));
}

// /////////////////////////////////////////////////////////////////
// QLeapController
// /////////////////////////////////////////////////////////////////

QLeapController::QLeapController(void) : d(new QLeapControllerPrivate)
{

}

QLeapController::~QLeapController(void)
{
    delete d;

    d = NULL;
}

void QLeapController::setListener(QLeapListener *listener)
{
    if(!listener)
        return;

    if (!d)
        return;

    d->addListener(listener);
}
