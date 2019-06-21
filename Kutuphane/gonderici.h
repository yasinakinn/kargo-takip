#ifndef GONDERICI_H
#define GONDERICI_H
#include <qstring.h>
#include <QObject>
#include "kutuphane_global.h"

class sube;
class urun;
class KUTUPHANESHARED_EXPORT gonderici : public QObject
{
    Q_OBJECT
private:
    QString kodStr;
    QString adStr;
    QString soyadStr;
    QString AdresStr;
    QString telStr;
    QString mailStr;
    QString gondericiSube;
    QString gonderilenUrun;
public:
    explicit gonderici(QObject *parent = 0);
    QString getKodStr();
    QString getAdStr() ;
    QString getSoyadStr();
    QString getAdresStr();
    QString getTelStr();
    QString getMailStr() ;
    QString getGondericiSube() ;
    QString getGonderilenUrun() ;
public slots:
    void setKodStr( QString value);
    void setAdStr( QString value);
    void setSoyadStr( QString value);
    void setAdresStr( QString value);
    void setTelStr( QString value);
    void setMailStr( QString value);
    void setGondericiSube(QString value);
    void setGonderilenUrun(QString value);
signals:
    void updateKod(QString kod);
    void updateAd(QString ad);
    void updateSoyad(QString soyad);
    void updateAdres(QString adres);
    void updateTel(QString tel);
    void updateMail(QString mail);
    void updateSube(QString yeniSube);
    void updateUrun(QString yeniUrun);
};

#endif // GONDERICI_H
