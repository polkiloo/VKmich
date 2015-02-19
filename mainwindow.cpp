#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "authorization.h"
#include "accessmembers.h"
#include "song.h"





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //ui->volumeNumber->setDigitCount(player->volume());
    ui->setupUi(this);

    //gui//////////////////////////////////////////////////////////////////////////
    ui->playButton->setIcon(  QIcon( ":/image/icons_for_player/play.png")  );
    ui->rewindButton->setIcon(  QIcon( ":/image/icons_for_player/rewind.png" )   );
    ui->forwardButton->setIcon( QIcon(":/image/icons_for_player/forward.png") );
    ui->shuffleButton->setIcon( QIcon(":/image/icons_for_player/shuffle.png") );






    //connect////////////////////////////////////////////////////////////////////////////////////////
    connect( ui->LoginButton, &QAbstractButton::pressed, this, &MainWindow::on_LoginButton_clicked );
    connect( ui->playButton,&QAbstractButton::pressed, player , &QMediaPlayer::play);
    connect( ui->volumeDial, &QDial::sliderMoved, player , &QMediaPlayer::volumeChanged   );
    //connect( ui->volumeDial, &QDial::sliderMoved, (*ui).volumeNumber , &QDial::valueChanged );









}

MainWindow::~MainWindow()
{
    delete ui;

}

QByteArray MainWindow::GET(QUrl url)
{
    QNetworkAccessManager* accessManager = new QNetworkAccessManager;
    QNetworkReply* reply = accessManager->get(QNetworkRequest(url));

    QEventLoop wait ;
    connect(accessManager, &QNetworkAccessManager::finished, &wait , &QEventLoop::quit);
    connect(accessManager, &QNetworkAccessManager::finished, accessManager, &QNetworkAccessManager::deleteLater);
    QTimer::singleShot(60000,&wait,SLOT(quit()));
    wait.exec();

    QByteArray answer = reply->readAll();
    reply->deleteLater();


    delete accessManager;
    return answer;

}



void MainWindow::on_LoginButton_clicked()
{
    AuthoRization *ath = new AuthoRization(this);




    if(ath->exec() == QDialog::Accepted)
     {
          (*this).accessMember.setToken(    ath->getToken()     );
          (*this).accessMember.setUserId(   ath->getUserId()    );

           getListAudio( (*this).accessMember  );
           getProfilePhoto( (*this).accessMember );
           getProfileName( (*this).accessMember );
     }

  delete ath;
}

void MainWindow::getListAudio(const AccessMembers &acc)
{

   QUrlQuery  current ("https://api.vk.com/method/audio.get?");
   current.addQueryItem("v","5.27");
   current.addQueryItem("access_token",acc.getToken());
   QUrl curr(current.query());
   QByteArray answer = GET(curr);


 //parse
   QJsonDocument jsonResponse = QJsonDocument::fromJson(answer);
   QJsonObject jsonObj = jsonResponse.object();
   QJsonObject jsonObject = jsonObj["response"].toObject();
   QJsonArray jsonAudioArray = jsonObject["items"].toArray();
   foreach (const QJsonValue &v, jsonAudioArray)
   {
       Song* song = new Song;
       song->setArtist(v.toObject().value("artist").toString());
       song->setTitle(v.toObject().value("title").toString());
       song->setUrl(v.toObject().value("url").toString());
       (*this).playlist.push_back(*song);
       delete song;
   }
   qDebug()<< (*this).playlist.size() <<"songs in list";
}

void MainWindow::getProfilePhoto(const AccessMembers &acc)
{
    QUrlQuery current ("https://api.vk.com/method/photos.getProfile?");
    current.addQueryItem("v","5.27");
    current.addQueryItem("access_token",acc.getToken());
    current.addQueryItem("uid",acc.getUserId());
    QUrl curr(current.query());
    QByteArray answer = GET(curr);

  //parse
    QJsonDocument jsonResponse = QJsonDocument::fromJson(answer);
    QJsonObject jsonObj = jsonResponse.object();
    QJsonObject jsonObject = jsonObj["response"].toObject();
    QJsonArray jsonPhotoArray = jsonObject["items"].toArray();
    QUrl urlProfilePhoto;
    foreach (const QJsonValue &v ,jsonPhotoArray)
    {

        urlProfilePhoto.setUrl(v.toObject().value("photo_130").toString());
    }

   qDebug()<<urlProfilePhoto;

   QNetworkAccessManager* accessManager = new QNetworkAccessManager;
   QNetworkReply* reply = accessManager->get(QNetworkRequest(urlProfilePhoto));

   QEventLoop wait ;
   connect(accessManager, &QNetworkAccessManager::finished, &wait , &QEventLoop::quit);
   connect(accessManager, &QNetworkAccessManager::finished, accessManager, &QNetworkAccessManager::deleteLater);
   QTimer::singleShot(60000,&wait,SLOT(quit()));
   wait.exec();



   QPixmap* pxlProfilePhoto = new QPixmap;
   pxlProfilePhoto->loadFromData(reply->readAll());

   ui->myProfilePhoto->setPixmap(*pxlProfilePhoto);
}

void MainWindow::getProfileName(const AccessMembers &acc)
{
    QUrlQuery current ("https://api.vk.com/method/users.get?");
    current.addQueryItem("v","5.27");
    current.addQueryItem("access_token",acc.getToken());
    QUrl curr(current.query());
    QByteArray answer = GET(curr);
     qDebug()<<answer;

    QJsonDocument jsonResponse = QJsonDocument::fromJson(answer);
    QJsonObject jsonObj = jsonResponse.object();
    QJsonArray jsonMyNameArray = jsonObj["response"].toArray();
    QString myName;
    foreach (const QJsonValue &v,jsonMyNameArray)
        {
         myName = v.toObject().value("first_name").toString();
         myName.append(" ");
         myName.append(v.toObject().value("last_name").toString());
        }
    ui->myNameLabel->setText(myName);


}





