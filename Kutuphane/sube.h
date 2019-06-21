#ifndef SUBE_H
#define SUBE_H
#include <qstring.h>
#include <QObject>
#include "kutuphane_global.h"

class KUTUPHANESHARED_EXPORT sube: public QObject
{
    Q_OBJECT
private:
    QString kodStr;
    QString adiStr;
    QString telStr;
    QString mailStr;
    QString subeSehir;
public:
    explicit sube(QObject *parent = 0);
    QString getKodStr() ;
    QString getAdiStr() ;
    QString getTelStr() ;
    QString getMailStr() ;
    QString getSubeSehir() ;
public slots:
    void setKodStr( QString value);
    void setAdiStr( QString value);
    void setTelStr( QString value);
    void setMailStr( QString value);
    void setSubeSehir(QString value);
signals:
    void updateKod(QString kod);
    void updateAd(QString ad);
    void updateTel(QString tel);
    void updateMail(QString mail);
    void updateSehir(QString yeniSehir);
};

#endif // SUBE_H
