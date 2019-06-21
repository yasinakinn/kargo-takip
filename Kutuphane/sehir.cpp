#include "sehir.h"

QString sehir::getKodStr()
{
    return kodStr;
}

void sehir::setKodStr(QString value)
{
    if (kodStr == value) {
        return;
    }
    kodStr = value;
    updateKod(kodStr);
}

QString sehir::getAdiStr()
{
    return adiStr;
}

void sehir::setAdiStr( QString value)
{
    if (adiStr == value) {
        return;
    }
    adiStr = value;
    updateAd(adiStr);
}

double sehir::getXKoordinatDbl()
{
    return xKoordinatDbl;
}

void sehir::setXKoordinatDbl(double value)
{
    if (xKoordinatDbl == value) {
        return;
    }
    xKoordinatDbl = value;
    updateX(xKoordinatDbl);
}

double sehir::getYKoordinatDbl()
{
    return yKoordinatDbl;
}

void sehir::setYKoordinatDbl(double value)
{
    if (yKoordinatDbl == value) {
        return;
    }
    yKoordinatDbl = value;
    updateY(yKoordinatDbl);
}

sehir::sehir(QObject *parent)
{

}

