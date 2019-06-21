#include "sube.h"

QString sube::getKodStr()
{
    return kodStr;
}

void sube::setKodStr( QString value)
{
    if (value == kodStr){
        return;
    }
    kodStr = value;
    updateKod(kodStr);
}

QString sube::getAdiStr()
{
    return adiStr;
}

void sube::setAdiStr( QString value)
{
    if (value == adiStr){
        return;
    }
    adiStr = value;
    updateAd(adiStr);
}

QString sube::getTelStr()
{
    return telStr;
}

void sube::setTelStr( QString value)
{
    if (value == telStr){
        return;
    }
    telStr = value;
    updateTel(telStr);
}

QString sube::getMailStr()
{
    return mailStr;
}

void sube::setMailStr( QString value)
{
    if (value == mailStr){
        return;
    }
    mailStr = value;
    updateMail(mailStr);
}

QString sube::getSubeSehir()
{
    return subeSehir;
}

void sube::setSubeSehir(QString value)
{
    if (value == subeSehir){
        return;
    }
    subeSehir = value;
    updateSehir(subeSehir);
}

sube::sube(QObject *parent)
{

}

