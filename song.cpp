#include "song.h"

Song::Song()
{

}
Song::~Song()
{

}

const QString& Song::getArtist() const
{
 return (*this).artist_;

}
void Song::setArtist(const QString& str)
{
 (*this).artist_ = str;

}


const QString& Song::getTitle() const
{
 return (*this).title_;
}
void Song::setTitle(const QString &str )
{
 (*this).title_ = str;
}

const QUrl& Song::getUrl()const
{
    return (*this).url_;
}
void Song::setUrl(const QUrl& url)
{
  (*this).url_ = url;
}
void Song::setUrl (const QString &str)
{
    (*this).url_.setUrl(str);
}
