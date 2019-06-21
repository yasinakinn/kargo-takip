#include "urun.h"

QString urun::getKodStr()
{
    return kodStr;
}

void urun::setKodStr( QString value)
{
    if (value == kodStr){
        return;
    }
    kodStr = value;
    updateKod(kodStr);
}

QString urun::getTipStr()
{
    return tipStr;
}

void urun::setTipStr( QString value)
{
    if (value == tipStr){
        return;
    }
    tipStr = value;
    updateTip(tipStr);
}

double urun::getAgirliDbl()
{
    return agirliDbl;
}

void urun::setAgirliDbl(double value)
{
    if (value == agirliDbl){
        return;
    }
    agirliDbl = value;
    updateAgirlik(agirliDbl);
}

double urun::getHacimDbl()
{
    return hacimDbl;
}

void urun::setHacimDbl(double value)
{
    if (value == hacimDbl){
        return;
    }
    hacimDbl = value;
    updateHacim(hacimDbl);
}

double urun::getFiyatDbl()
{
    return fiyatDbl;
}

void urun::setFiyatDbl(double value)
{
    if (value == fiyatDbl){
        return;
    }
    fiyatDbl = value;
    updateFiyat(fiyatDbl);
}

QString urun::getAliciMusteri()
{
    return aliciMusteri;
}

void urun::setAliciMusteri(QString value)
{
    if (value == aliciMusteri){
        return;
    }
    aliciMusteri = value;
    updateAlici(aliciMusteri);
}

QString urun::getGondericiMusteri()
{
    return gondericiMusteri;
}

void urun::setGondericiMusteri(QString value)
{
    if (value == gondericiMusteri){
        return;
    }
    gondericiMusteri = value;
    updateGonderici(gondericiMusteri);
}

int urun::getDurum()
{
    return durum;
}

void urun::setDurum(int value)
{
    if (value == durum){
        return;
    }
    durum = value;
    updateDurum(durum);
}

urun::urun(QObject *parent)
{

}

