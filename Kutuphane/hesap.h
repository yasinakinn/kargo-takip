#ifndef HESAP_H
#define HESAP_H

#include <QObject>
#include <QString>

#include "alici.h"
#include "gonderici.h"
#include "sehir.h"
#include "sube.h"
#include "urun.h"
#include "kutuphane_global.h"
#include "veritabani.h"

#define RADYAN (3.1415926536 / 180)
#define R 6373

class KUTUPHANESHARED_EXPORT hesap : public QObject
{

    Q_OBJECT

public:
    QString anaBolge(double x, double y);
    int alinanBolge(double x, double y);

    double sehirlerArasiUzaklik(double x1,double y1,double x2,double y2);

    QList<sehir *> urunDuzergahOlustur(QString kod);


    hesap();
};

#endif // HESAP_H
