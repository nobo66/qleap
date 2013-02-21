/* QLeapMapperTest.h --- 
 * 
 * Author: Julien Wintz
 * Created: Thu Feb 21 13:38:03 2013 (+0100)
 * Version: 
 * Last-Updated: Thu Feb 21 14:40:33 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 29
 */

/* Change Log:
 * 
 */

#pragma once

#include <QtCore>
#include <QtTest>
#include <QtWidgets>

class QLeapMapperTestCase : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase(void);
    void init(void);

private slots:
    void testMapToScreen(void);

private slots:
    void cleanup(void);
    void cleanupTestCase(void);
};
