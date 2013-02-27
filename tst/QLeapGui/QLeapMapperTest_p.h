/* QLeapMapperTest_p.h --- 
 * 
 * Author: Julien Wintz
 * Created: Thu Feb 21 14:47:21 2013 (+0100)
 * Version: 
 * Last-Updated: Fri Feb 22 15:58:39 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 18
 */

/* Change Log:
 * 
 */

#pragma once

class QLeapMapperTestScreenHelper : public QFrame
{
    Q_OBJECT

public:
     QLeapMapperTestScreenHelper(void);
    ~QLeapMapperTestScreenHelper(void);

public:
    int exec(void);

signals:
    void hit(void);

public:
    bool event(QEvent *event);
};
