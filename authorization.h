#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QDialog>
#include <QUrl>
#include <QUrlQuery>
#include <QString>

namespace Ui {
class AuthoRization;
}

class AuthoRization : public QDialog
{
    Q_OBJECT

public:
    explicit AuthoRization(QWidget *parent = 0);
    ~AuthoRization();
    const QString &getToken() const;
    const QString &getUserId() const;

public slots:
    void check_url(QUrl url);

signals :


private:
    Ui::AuthoRization* ui;
    QString token_;
    QString userId_;







};

#endif // AUTHORIZATION_H
