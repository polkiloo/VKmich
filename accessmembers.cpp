#include "accessmembers.h"
#include <QString>


AccessMembers::AccessMembers()
{

}
AccessMembers::~AccessMembers()
{


}
const QString& AccessMembers::getToken()const
{
    return (*this).token_;
}
const QString& AccessMembers::getUserId() const
{
    return  (*this).userId_;
}
void AccessMembers::setToken(const QString& str)
{
   (*this).token_ =  str;
}
void AccessMembers::setUserId(const QString& str)
{
    (*this).userId_ = str;
}
