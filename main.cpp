#include <QApplication>
#include <QTextCodec>


#include "mainwindow.h"
#include "authorization.h"
#include "accessmembers.h"
#include "song.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(  controlButtons   );

    QTextCodec *utfcodec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(utfcodec);



    QApplication a(argc, argv);
    MainWindow* w = new MainWindow;

    

    w->show();



    return a.exec();
}
