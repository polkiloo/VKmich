#ifndef SONG_H
#define SONG_H

#include <QString>
#include <QUrl>

class Song
{
public:
    Song();
   ~Song();

    const QString& getArtist() const ;
    void setArtist(const QString&);


    const QString& getTitle() const ;
    void setTitle(const QString& );

    const QUrl& getUrl()const;
    void setUrl(const QUrl& );
    void setUrl (const QString& );

private:
    QString artist_;
    QString title_;
    QUrl url_;
};

#endif // SONG_H
