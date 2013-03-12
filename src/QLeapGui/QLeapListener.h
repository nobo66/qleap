/* QLeapListener.h --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Dec 18 17:30:44 2012 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Mar 12 14:17:45 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 108
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#pragma once

#include "QLeapGuiExport.h"

class QObject;
class QLeap;
class QLeapListenerPrivate;

class QLeapListener
{
public:
     QLeapListener(void);
    ~QLeapListener(void);

public:
    void addTarget(QObject *target);

private:
    friend class QLeapController;
    friend class QLeapControllerPrivate;

private:
    QLeapListenerPrivate *d;
};

