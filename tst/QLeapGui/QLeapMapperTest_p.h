/* QLeapMapperTest_p.h --- 
 * 
 * Author: Julien Wintz
 * Created: Thu Feb 21 14:47:21 2013 (+0100)
 * Version: 
 * Last-Updated: Thu Feb 21 15:12:35 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 12
 */

/* Change Log:
 * 
 */

#pragma once

class QLeapMapperTestScreenHelper : public QObject
{
    Q_OBJECT

public:
    int exec(void);

signals:
    void done(void);

public:
    bool event(QEvent *event);
};
