#ifndef ALICI_H
#define ALICI_H
#include <qstring.h>

#include <QObject>
#include "kutuphane_global.h"


class KUTUPHANESHARED_EXPORT alici : public QObject
{
    Q_OBJECT
private:
    QString kodStr;
    QString adStr;
    QString soyadStr;
    QString AdresStr;
    QString telStr;
    QString mailStr;
    QString alinanSube;
    QString alinanUrun;
    QString gonderMusteri;
public:
    explicit alici(QObject *parent = 0);
    QString getKodStr();
    QString getAdStr();
    QString getSoyadStr();
    QString getAdresStr();
    QString getTelStr() ;
    QString getMailStr() ;
    QString getAlinanSube() ;
    QString getAlinanUrun() ;
    QString getGonderMusteri() ;
public slots:
    void setKodStr(QString value);
    void setAdStr(QString value);
    void setSoyadStr(QString value);
    void setAdresStr( QString value);
    void setTelStr(QString value);
    void setMailStr( QString value);
    void setAlinanSube(QString value);
    void setAlinanUrun(QString value);
    void setGonderMusteri(QString value);

signals:
    void updateKod(QString kod);
    void updateAd(QString ad);
    void updateSoyad(QString soyad);
    void updateAdres(QString adres);
    void updateTel(QString tel);
    void updateMail(QString mail);
    void updateSube(QString yeniSube);
    void updateUrun(QString yeniUrun);
    void updateGonderici(QString yeniGonderici);
};

#endif // ALICI_H
