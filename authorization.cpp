#include "authorization.h"
#include "ui_authorization.h"

AuthoRization::AuthoRization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthoRization)
{
    ui->setupUi(this);
    ui->webView->load(QUrl("https://oauth.vk.com/authorize?client_id=4632420&scope=friends,audio,video,photos,offline&redirect_uri=https://oauth.vk.com/blank.html&display=page&v=5.27&response_type=token"));
    connect(ui->webView,&QWebView::urlChanged,this,&AuthoRization::check_url);
    connect(ui->okPushButton,&QPushButton::clicked, this ,&QDialog::accept);



}

AuthoRization::~AuthoRization()
{
    delete ui;
}

const QString &AuthoRization::getToken() const
{
    return (*this).token_;

}
const QString &AuthoRization::getUserId()const
{
    return (*this).userId_;
}


void AuthoRization::check_url(QUrl url)
{
    url = url.toString().replace("#","?");

    this->token_ = QUrlQuery(url).queryItemValue("access_token");
    this->userId_ = QUrlQuery(url).queryItemValue("user_id");


    /*if(  ((*this).token_.isEmpty()) && ((*this).userId_.isEmpty())   )
        {
            return;
        }
    else
        {
           emit auth_success();
        }
      */

}

