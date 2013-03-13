/* QLeapMapper.h --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008-2011 - Julien Wintz, Inria.
 * Created: Fri Jan 11 15:32:28 2013 (+0100)
 * Version: $Id$
 * Last-Updated: Wed Mar 13 12:38:14 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 38
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
    QLEAPGUI_EXPORT static const QPointF mapToLocal(const QPointF& point, const QRectF& screen);
    QLEAPGUI_EXPORT static const QPointF mapToGlobal(const QPointF& point, const QRectF& screen);
};
