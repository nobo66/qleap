/* QLeapMapperTest.cpp --- 
 * 
 * Author: Julien Wintz
 * Created: Thu Feb 21 13:41:59 2013 (+0100)
 * Version: 
 * Last-Updated: Wed Mar 13 12:44:51 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 210
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
    int status = 0;

    qsrand(QTime::currentTime().msec());

    for(int i = 0; i < 20; i++) {

	QDesktopWidget desktop;

	QLeapMapperTestScreenHelper helper;
	helper.move(qrand() % desktop.screenGeometry().width() - 200,
		    qrand() % desktop.screenGeometry().height() - 200);
	helper.show();
	helper.raise();
	
	qLeap->addTarget(&helper);
    
	status += helper.exec();
    }

    QVERIFY(status == 0);
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
    int TestMain(int argc, char *argv[])		\
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

QLeapMapperTestScreenHelper::QLeapMapperTestScreenHelper(void)
{
    QFont font;
    font.setFamily("Menlo");
    font.setPointSize(64);

    QLabel *label = new QLabel("Touch me", this);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("background: #cccccc; color: #666666; padding: 20px;");

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(label);

    this->setStyleSheet("background: black;");
}

QLeapMapperTestScreenHelper::~QLeapMapperTestScreenHelper(void)
{

}

int QLeapMapperTestScreenHelper::exec(void)
{
    QEventLoop loop;

    connect(this, SIGNAL(hit()), &loop, SLOT(quit()));
    
    return loop.exec();
}

bool QLeapMapperTestScreenHelper::event(QEvent *event)
{
    static bool single = false;

    switch (event->type()) {

    case QEvent::TouchBegin:
	if(QTouchEvent *touch = static_cast<QTouchEvent *>(event))
	    if(touch->touchPoints().count() == 1)
		single = true;
        break;

    case QEvent::TouchCancel:
	single = false;
        break;

    case QEvent::TouchEnd:
	single = false;
        break;

    case QEvent::TouchUpdate:
	if(!single)
	    break;

	if (QTouchEvent *touch = static_cast<QTouchEvent *>(event)) {
	    QTouchEvent::TouchPoint point = touch->touchPoints().first();

	    qDebug() << Q_FUNC_INFO << point.screenPos() << this->geometry();

	    if(this->geometry().contains(point.screenPos().toPoint()))
		emit hit();
        }
        break;

    default:
        break;
    }

    return QObject::event(event);
}
