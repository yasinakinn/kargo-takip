#include "merkezsube.h"

QString merkezSube::getKod() const
{
    return kod;
}

void merkezSube::setKod(const QString value)
{
    if (value == kod){
        return;
    }
    kod = value;
    updateKod(kod);
}

int merkezSube::getDurum() const
{
    return durum;
}

void merkezSube::setDurum(int value)
{
    if (value == durum){
        return;
    }
    durum = value;
    updateDurum(durum);
}

QString merkezSube::getSubeKod() const
{
    return subeKod;
}

void merkezSube::setSubeKod(const QString value)
{
    if (value == subeKod){
        return;
    }
    subeKod = value;
    updateSubeKod(subeKod);
}

merkezSube::merkezSube(QObject *parent)
{

}

