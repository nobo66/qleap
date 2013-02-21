/* QLeapMapper.cpp --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Fri Jan 11 15:34:16 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Fri Jan 18 18:21:20 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 110
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

const QPointF QLeapMapper::mapToSpace(const QPointF& point)
{
    return qApp->topLevelAt(mapToScreen(point).toPoint())->mapFromGlobal(mapToScreen(point).toPoint());
}

const QPointF QLeapMapper::mapToScene(const QPointF& point)
{
    static qreal SCENE_W = qApp->desktop()->screenGeometry(qApp->desktop()->primaryScreen()).width();
    static qreal SCENE_H = qApp->desktop()->screenGeometry(qApp->desktop()->primaryScreen()).height();

    static qreal SCENE_DX = SCENE_W/2.0;
    static qreal SCENE_DY = SCENE_H/2.0;
    
    return QPointF((point.x() + SCENE_DX) * SCENE_W, ((1.0 - point.y()) + SCENE_DY) * SCENE_H);
}

const QPointF QLeapMapper::mapToScreen(const QPointF& point)
{
    static qreal SCREEN_W = qApp->desktop()->screenGeometry(qApp->desktop()->primaryScreen()).width();
    static qreal SCREEN_H = qApp->desktop()->screenGeometry(qApp->desktop()->primaryScreen()).height();
    
    return QPointF(point.x() * SCREEN_W, (1.0 - point.y()) * SCREEN_H);
}
