#include "alici.h"


QString alici::getKodStr()
{
    return kodStr;
}

void alici::setKodStr( QString value)
{
    if (kodStr == value){
        return;
    }
    kodStr = value;
    updateKod(kodStr);
}

QString alici::getAdStr()
{
    return adStr;
}

void alici::setAdStr(QString value)
{
    if (value == adStr){
        return;
    }
    adStr = value;
    updateAd(adStr);
}

QString alici::getSoyadStr()
{
    return soyadStr;
}

void alici::setSoyadStr( QString value)
{
    if (value == soyadStr){
        return;
    }
    soyadStr = value;
    updateSoyad(soyadStr);
}

QString alici::getAdresStr()
{
    return AdresStr;
}

void alici::setAdresStr( QString value)
{
    if (value == AdresStr){
        return;
    }
    AdresStr = value;
    updateAdres(AdresStr);
}

QString alici::getTelStr()
{
    return telStr;
}

void alici::setTelStr( QString value)
{
    if (value == telStr){
        return;
    }
    telStr = value;
    updateTel(telStr);
}

QString alici::getMailStr()
{
    return mailStr;
}

void alici::setMailStr( QString value)
{
    if (value == mailStr){
        return;
    }
    mailStr = value;
    updateMail(mailStr);
}

QString alici::getAlinanSube()
{
    return alinanSube;
}

void alici::setAlinanSube(QString value)
{
    if (value == alinanSube){
        return;
    }
    alinanSube = value;
    updateSube(alinanSube);
}

QString alici::getAlinanUrun()
{
    return alinanUrun;
}

void alici::setAlinanUrun(QString value)
{
    if (value == alinanUrun){
        return;
    }
    alinanUrun = value;
    updateUrun(alinanUrun);
}

QString alici::getGonderMusteri()
{
    return gonderMusteri;
}

void alici::setGonderMusteri(QString value)
{
    if (value == gonderMusteri){
        return;
    }
    gonderMusteri = value;
    updateGonderici(gonderMusteri);
}

alici::alici(QObject *parent)
{

}

