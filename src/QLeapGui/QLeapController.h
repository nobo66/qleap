/* QLeapController.h --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Tue Dec 18 18:29:31 2012 (+0100)
 * Version: $Id$
 * Last-Updated: Thu Feb 21 11:36:51 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 68
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#pragma once

#include "QLeapGuiExport"

class QLeapListener;
class QLeapControllerPrivate;

class QLeapController
{
public:
     QLeapController(void);
    ~QLeapController(void);

public:
    void setListener(QLeapListener *listener);

private:
    friend class QLeapListener;
    friend class QLeapMapper;

private:
    QLeapControllerPrivate *d;
};
