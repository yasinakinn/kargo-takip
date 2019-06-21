#ifndef SEHIR_H
#define SEHIR_H
#include <qstring.h>
#include <kutuphane_global.h>
#include <QObject>

class KUTUPHANESHARED_EXPORT sehir: public QObject
{
    Q_OBJECT
private:
    QString kodStr;
    QString adiStr;
    double xKoordinatDbl;
    double yKoordinatDbl;
public:
    explicit sehir(QObject *parent = 0);
    QString getKodStr();
    QString getAdiStr() ;
    double getXKoordinatDbl() ;
    double getYKoordinatDbl() ;
public slots:
    void setKodStr( QString value);
    void setAdiStr( QString value);
    void setXKoordinatDbl(double value);
    void setYKoordinatDbl(double value);
signals:
    void updateKod(QString kod);
    void updateAd(QString ad);
    void updateX(double x);
    void updateY(double y);
};

#endif // SEHIR_H
