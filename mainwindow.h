#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QTimer>
#include <QEventLoop>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QMap>
#include <QVariantMap>
#include <QVariantList>
#include <QByteArray>
#include <QVector>

#include <QPixmap>

#include <QMediaObject>
#include <QMediaPlayer>





#include "authorization.h"
#include "accessmembers.h"
#include "song.h"






namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();





private slots:
    void on_LoginButton_clicked();




private:
        Ui::MainWindow* ui;
        QMediaPlayer* player;
        AccessMembers accessMember;
        QByteArray GET(QUrl) ;
        QVector<Song> playlist;

        void  getListAudio(const AccessMembers &);
        void  getProfilePhoto(const AccessMembers&);
        void  getProfileName(const AccessMembers&);

};

#endif // MAINWINDOW_H
