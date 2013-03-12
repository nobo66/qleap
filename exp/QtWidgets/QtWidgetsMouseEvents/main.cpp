/* main.cpp ---
 * 
 * Author: Julien Wintz
 * Created: Tue Mar 12 13:03:53 2013 (+0100)
 * Version: 
 * Last-Updated: Tue Mar 12 13:53:26 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 12
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
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QPlainTextEdit *log;
};

qleapWidget::qleapWidget(QWidget *parent) : QWidget(parent)
{
    QLabel *label = new QLabel("Move Here!", this);
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

    this->setWindowTitle("QLeap widgets mouse events example");
}

qleapWidget::~qleapWidget(void)
{

}

void qleapWidget::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->pos().x();
    int y = event->pos().y();

    this->log->appendPlainText(QString("mouse    move: (%1,%2)").arg(x).arg(y));
}

void qleapWidget::mousePressEvent(QMouseEvent *event)
{
    int x = event->pos().x();
    int y = event->pos().y();

    this->log->appendPlainText(QString("mouse   press: (%1,%2)").arg(x).arg(y));
}

void qleapWidget::mouseReleaseEvent(QMouseEvent *event)
{
    int x = event->pos().x();
    int y = event->pos().y();

    this->log->appendPlainText(QString("mouse release: (%1,%2)").arg(x).arg(y));
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
