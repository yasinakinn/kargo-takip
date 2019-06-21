#include "hesap.h"
#include <QPair>
#include <QString>
#include <math.h>


QString hesap::anaBolge(double x, double y)
{
    veritabani *veri;
    sehir *anabolge;
    anabolge = veri->merkezSubeSehirAra("0").first();
    double xMerkez , yMerkez;
    xMerkez = anabolge->getXKoordinatDbl();
    yMerkez = anabolge->getYKoordinatDbl();

    if (xMerkez - x > 0 && yMerkez - y > 0) {
        return "3";
    }
    else if (xMerkez - x < 0 && yMerkez - y > 0) {
        return "2";
    }
    else if (xMerkez - x < 0 && yMerkez - y < 0) {
        return "1";
    }
    else if (xMerkez - x > 0 && yMerkez - y < 0) {
        return "4";
    }
    else
        return "0";

}

int hesap::alinanBolge(double x, double y)
{
    veritabani *veri = ::veritabani::getVeritabani();
    QString b = anaBolge(x,y);
    double merkez [2];

    sehir *anabolge;
    anabolge = veri->merkezSubeSehirAra(b).first();
    merkez[0] = anabolge->getXKoordinatDbl();
    merkez[1] = anabolge->getYKoordinatDbl();
    int bb = b.toInt();
    if (merkez[0] - x > 0 && merkez[1] - y > 0) {
        return bb;
    }
    else if (merkez[0] - x < 0 && merkez[1] - y > 0) {
        return bb;
    }
    else if (merkez[0] - x < 0 && merkez[1] - y < 0) {
        return bb;
    }
    else if (merkez[0] - x < 0 && merkez[1] - y > 0) {
        return bb;
    }
    else
        return bb;

}

double hesap::sehirlerArasiUzaklik(double x1, double y1, double x2, double y2)
{
    double dx, dy, dz;
    y1 -= y2;
    y1 *= RADYAN, x1 *= RADYAN, x2 *= RADYAN;

    dz = sin(x1) - sin(x2);
    dx = cos(y1) * cos(x1) - cos(x2);
    dy = sin(y1) * cos(x1);
    return asin(sqrt(dx * dx + dy * dy + dz * dz) / 2) * 2 * R;
}

QList<sehir *> hesap::urunDuzergahOlustur(QString kod)
{
    veritabani *ara;
    QList <sehir *> urunDuzergah;

    int ilkBolge = alinanBolge(ara->urunKodundanGondericiSubeSehire(kod)->getXKoordinatDbl(),ara->urunKodundanGondericiSubeSehire(kod)->getYKoordinatDbl());
    int sonBolge = alinanBolge(ara->urunKodundanAliciSubeSehire(kod)->getXKoordinatDbl(),ara->urunKodundanAliciSubeSehire(kod)->getYKoordinatDbl());

    if (ilkBolge  == sonBolge) {
        urunDuzergah.append(ara->merkezSubeSehirAra(QString::number(ilkBolge)));
        urunDuzergah.append(ara->sehirKodAra(ara->subeKodAra(ara->aliciKodAra(ara->urunKodAra(kod).first()->getAliciMusteri())->getAlinanSube())->getSubeSehir()));
    }else{
        urunDuzergah.append(ara->merkezSubeSehirAra(QString::number(ilkBolge)));
        urunDuzergah.append(ara->merkezSubeSehirAra("0"));
        urunDuzergah.append(ara->merkezSubeSehirAra(QString::number(sonBolge)));
        urunDuzergah.append(ara->sehirKodAra(ara->subeAdAra(ara->aliciKodAra(ara->urunKodAra(kod).first()->getAliciMusteri())->getAlinanSube()).first()->getSubeSehir()));
    }

    return urunDuzergah;

}


