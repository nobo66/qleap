/* main.cpp ---
 * 
 * Author: Julien Wintz
 * Created: Tue Mar 12 17:56:36 2013 (+0100)
 * Version: 
 * Last-Updated: Tue Mar 12 18:49:31 2013 (+0100)
 *           By: Julien Wintz
 *     Update #: 30
 */

/* Change Log:
 * 
 */

#include <QtCore>
#include <QtGui>
#include <QtQuick>

#include <QLeapGui>

int main(int argc, char *argv[])
{
    QGuiApplication application(argc, argv);

    QQuickView view;
    view.setColor(Qt::black);
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:main.qml"));
    view.setTitle("QLeap quick mouse area example");
    view.show();
    view.raise();

    view.setMouseGrabEnabled(true);

    qLeap->addTarget(&view);

    return application.exec();
}
