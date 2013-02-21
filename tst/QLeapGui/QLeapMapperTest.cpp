/* QLeapMapperTest.cpp --- 
 * 
 * Author: Julien Wintz
 * Created: Thu Feb 21 13:41:59 2013 (+0100)
 * Version: 
 * Last-Updated: Thu Feb 21 15:48:51 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 107
 */

/* Change Log:
 * 
 */

#include "QLeapMapperTest.h"
#include "QLeapMapperTest_p.h"

#include <QLeapGui/QLeap>
#include <QLeapGui/QLeapMapper>

// ///////////////////////////////////////////////////////////////////
// QLeapMapperTestCase
// ///////////////////////////////////////////////////////////////////

void QLeapMapperTestCase::initTestCase(void)
{
    Q_ASSERT(qLeap);
}

void QLeapMapperTestCase::init(void)
{

}

void QLeapMapperTestCase::testMapToScreen(void)
{
    QLeapMapperTestScreenHelper helper;

    QVERIFY(!helper.exec());
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

// ///////////////////////////////////////////////////////////////////
// QLeapMapperTestScreenHelper
// ///////////////////////////////////////////////////////////////////

int QLeapMapperTestScreenHelper::exec(void)
{
    QFont font;
    font.setFamily("Menlo");
    font.setPointSize(256);

    QLabel label("Touch me");
    label.setFont(font);
    label.show();

    QEventLoop loop;

    connect(this, SIGNAL(done()), &loop, SLOT(quit()));
    
    return loop.exec();
}

bool QLeapMapperTestScreenHelper::event(QEvent *event)
{
    qDebug() << event;

    return QObject::event(event);
}
