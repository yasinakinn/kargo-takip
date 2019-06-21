#ifndef URUN_H
#define URUN_H
#include <qstring.h>
#include <QObject>
#include "kutuphane_global.h"


class alici;
class gonderici;
class KUTUPHANESHARED_EXPORT urun: public QObject
{
    Q_OBJECT
private:
    QString kodStr;
    QString tipStr;
    double agirliDbl;
    double hacimDbl;
    double fiyatDbl;
    double desiDbl;
    QString aliciMusteri;
    QString gondericiMusteri;
    int durum;
public:
    explicit urun(QObject *parent = 0);
    QString getKodStr() ;
    QString getTipStr() ;
    double getAgirliDbl() ;
    double getHacimDbl() ;
    double getFiyatDbl() ;
    QString getAliciMusteri() ;
    QString getGondericiMusteri() ;
    int getDurum();



public slots:
    void setDurum(int value);
    void setKodStr( QString value);
    void setTipStr( QString value);
    void setAgirliDbl(double value);
    void setHacimDbl(double value);
    void setFiyatDbl(double value);
    void setAliciMusteri(QString value);
    void setGondericiMusteri(QString value);

signals:
    void updateDurum(int durum);
    void updateKod(QString kod);
    void updateTip(QString tip);
    void updateAgirlik(double agirlik);
    void updateHacim(double hacim);
    void updateFiyat(double fiyat);
    void updateAlici(QString  yeniAlici);
    void updateGonderici(QString yeniGonderici);
};

#endif // URUN_H
