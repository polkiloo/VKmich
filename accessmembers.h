#ifndef ACCESSMEMBERS_H
#define ACCESSMEMBERS_H

#include <QString>

class AccessMembers
{
public:
    AccessMembers();
   ~AccessMembers();

    const QString& getToken() const ;
    void setToken(const QString&);


    const QString& getUserId() const ;
    void setUserId(const QString& );

private:
   QString token_;
   QString userId_;
}
   ;

#endif // ACCESSMEMBERS_H
