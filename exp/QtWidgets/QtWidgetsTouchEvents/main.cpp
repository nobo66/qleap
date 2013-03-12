/* main.cpp ---
 * 
 * Author: Julien Wintz
 * Created: Tue Mar 12 13:03:53 2013 (+0100)
 * Version: 
 * Last-Updated: Tue Mar 12 16:16:57 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 23
 */

/* Change Log:
 * 
 */

#include <QtCore>
#include <QtGui>
#include <QtWidgets>

// ///////////////////////////////////////////////////////////////////
// qleapWidget
// ///////////////////////////////////////////////////////////////////

class qleapWidget : public QWidget
{
public:
     qleapWidget(QWidget *parent = 0);
    ~qleapWidget(void);

protected:
    bool event(QEvent *event);

private:
    QPlainTextEdit *log;
};

qleapWidget::qleapWidget(QWidget *parent) : QWidget(parent)
{
    QLabel *label = new QLabel("Touch Me!", this);
    label->setAlignment(Qt::AlignCenter);
    label->setFont(QFont("Menlo", 24));
    label->setMinimumHeight(50);

    this->log = new QPlainTextEdit(this);
    this->log->setAttribute(Qt::WA_MacShowFocusRect, false);
    this->log->setFont(QFont("Monaco", 11));
    this->log->setFrameShape(QFrame::NoFrame);
    this->log->setReadOnly(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(label);
    layout->addWidget(this->log);

    this->setWindowTitle("QLeap widgets touch events example");
}

qleapWidget::~qleapWidget(void)
{

}

bool qleapWidget::event(QEvent *event)
{
    if (event->type() == QEvent::TouchBegin) {
	event->accept();
	this->log->appendPlainText(QString("touch  begin: %1 point(s)").arg(static_cast<QTouchEvent *>(event)->touchPoints().count()));
	return true;
    }

    if (event->type() == QEvent::TouchUpdate) {
	
	int x = static_cast<QTouchEvent *>(event)->touchPoints().first().pos().x();
	int y = static_cast<QTouchEvent *>(event)->touchPoints().first().pos().y();

	this->log->appendPlainText(QString("touch update: %1 point(s) - (%2,%3)").arg(static_cast<QTouchEvent *>(event)->touchPoints().count()).arg(x).arg(y));
	return true;
    }

    if (event->type() == QEvent::TouchEnd) {
	this->log->appendPlainText(QString("touch    end: %1 point(s)").arg(static_cast<QTouchEvent *>(event)->touchPoints().count()));
	return true;
    }

    return QWidget::event(event);
}

// ///////////////////////////////////////////////////////////////////

#include <QLeapGui>

int main(int argc, char **argv)
{
    QApplication application(argc, argv);

    qleapWidget widget;
    widget.winId();
    widget.show();
    widget.raise();

#if defined(Q_OS_MAC)
    qleap_enable_touch_events(&widget);
#endif
    qLeap->addTarget(&widget);

    return application.exec();
}
