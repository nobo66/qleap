/* QLeapMapper.cpp --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Fri Jan 11 15:34:16 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Mar 13 12:38:33 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 134
 */

/* Commentary:
 * 
 */

/* Change log:
 * 
 */

#include "QLeap"
#include "QLeapController"
#include "QLeapController_p"
#include "QLeapMapper.h"

#include <QtGui>
#include <QtWidgets>

#include <Leap.h>

const QPointF QLeapMapper::mapToLocal(const QPointF& point, const QRectF& screen)
{
    QPoint screen_pos = mapToGlobal(point, screen).toPoint();

    return qApp->topLevelAt(screen_pos)->mapFromGlobal(screen_pos);
}

const QPointF QLeapMapper::mapToGlobal(const QPointF& point, const QRectF& screen)
{
    static qreal SCREEN_W = screen.width();
    static qreal SCREEN_H = screen.height();
    
    return QPointF(point.x() * SCREEN_W, (1.0 - point.y()) * SCREEN_H);
}
