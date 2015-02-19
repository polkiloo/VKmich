#ifndef ACCESSMEMBER_H
#define ACCESSMEMBER_H
#include <QString>

namespace std{
class AccessMember;
}

class AccessMember
{
public:
    explicit AccessMember();
    ~AccessMember();

    QString getToken();
    void setToken(QString);

    QString getUserId();
    void setUserId(QString);

private:
    QString token_;
    QString userId_;

};

#endif // ACCESSMEMBER_H
