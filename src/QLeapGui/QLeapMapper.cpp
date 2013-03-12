/* QLeapMapper.cpp --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Fri Jan 11 15:34:16 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Mar 12 18:28:08 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 119
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

const QPointF QLeapMapper::mapToSpace(const QPointF& point, const QRectF& screen)
{
    return qApp->topLevelAt(mapToScreen(point, screen).toPoint())->mapFromGlobal(mapToScreen(point, screen).toPoint());
}

const QPointF QLeapMapper::mapToScene(const QPointF& point, const QRectF& screen)
{
    static qreal SCENE_W = screen.width();
    static qreal SCENE_H = screen.height();

    static qreal SCENE_DX = SCENE_W/2.0;
    static qreal SCENE_DY = SCENE_H/2.0;
    
    return QPointF((point.x() + SCENE_DX) * SCENE_W, ((1.0 - point.y()) + SCENE_DY) * SCENE_H);
}

const QPointF QLeapMapper::mapToScreen(const QPointF& point, const QRectF& screen)
{
    static qreal SCREEN_W = screen.width();
    static qreal SCREEN_H = screen.height();
    
    return QPointF(point.x() * SCREEN_W, (1.0 - point.y()) * SCREEN_H);
}
