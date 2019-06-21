#include "gonderici.h"

QString gonderici::getKodStr()
{
    return kodStr;
}

void gonderici::setKodStr( QString value)
{
    if (value == kodStr){
        return;
    }
    kodStr = value;
    updateKod(kodStr);
}

QString gonderici::getAdStr()
{
    return adStr;
}

void gonderici::setAdStr( QString value)
{
    if (value == adStr){
        return;
    }
    adStr = value;
    updateAd(adStr);
}

QString gonderici::getSoyadStr()
{
    return soyadStr;
}

void gonderici::setSoyadStr( QString value)
{
    if (value == soyadStr){
        return;
    }
    soyadStr = value;
    updateSoyad(soyadStr);
}

QString gonderici::getAdresStr()
{
    return AdresStr;
}

void gonderici::setAdresStr( QString value)
{
    if (value == AdresStr){
        return;
    }
    AdresStr = value;
    updateAdres(AdresStr);
}

QString gonderici::getTelStr()
{
    return telStr;
}

void gonderici::setTelStr( QString value)
{
    if (value == telStr){
        return;
    }
    telStr = value;
    updateTel(telStr);
}

QString gonderici::getMailStr()
{
    return mailStr;
}

void gonderici::setMailStr( QString value)
{
    if (value == mailStr){
        return;
    }
    mailStr = value;
    updateMail(mailStr);
}

QString gonderici::getGondericiSube()
{
    return gondericiSube;
}

void gonderici::setGondericiSube(QString value)
{
    if (value == gondericiSube){
        return;
    }
    gondericiSube = value;
    updateSube(gondericiSube);
}

QString gonderici::getGonderilenUrun()
{
    return gonderilenUrun;
}

void gonderici::setGonderilenUrun(QString value)
{
    if (value == gonderilenUrun){
        return;
    }
    gonderilenUrun = value;
    updateUrun(gonderilenUrun);
}

gonderici::gonderici(QObject *parent)
{

}

