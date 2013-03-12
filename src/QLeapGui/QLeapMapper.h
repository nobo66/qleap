/* QLeapMapper.h --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Fri Jan 11 15:32:28 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Tue Mar 12 18:30:27 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 37
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#pragma once

#include "QLeapGuiExport"

#include <QtCore/QPoint>
#include <QtCore/QPointF>

class QLeapMapper
{
public:
    QLEAPGUI_EXPORT static const QPointF mapToSpace(const QPointF& point, const QRectF& screen);
    QLEAPGUI_EXPORT static const QPointF mapToScene(const QPointF& point, const QRectF& screen);
    QLEAPGUI_EXPORT static const QPointF mapToScreen(const QPointF& point, const QRectF& screen);
};
