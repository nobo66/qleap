/* QLeapMapperTest.cpp --- 
 * 
 * Author: Julien Wintz
 * Created: Thu Feb 21 13:41:59 2013 (+0100)
 * Version: 
 * Last-Updated: Thu Feb 21 13:48:30 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 24
 */

/* Change Log:
 * 
 */

#include "QLeapMapperTest.h"

void QLeapMapperTestCase::initTestCase(void)
{

}

void QLeapMapperTestCase::init(void)
{

}

void QLeapMapperTestCase::testMapper(void)
{
    QVERIFY(1 == 1);
}

void QLeapMapperTestCase::cleanup(void)
{

}

void QLeapMapperTestCase::cleanupTestCase(void)
{

}

// ///////////////////////////////////////////////////////////////////
// 
// ///////////////////////////////////////////////////////////////////

#define QLEAP_TEST_MAIN(TestMain, TestObject)	\
    int TestMain(int argc, char **argv)		\
    {						\
        QApplication app(argc, argv);		\
        TestObject tc;				\
        return QTest::qExec(&tc, argc, argv);	\
    }

// ///////////////////////////////////////////////////////////////////
// 
// ///////////////////////////////////////////////////////////////////

QLEAP_TEST_MAIN(QLeapMapperTest, QLeapMapperTestCase)
