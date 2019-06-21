#ifndef VERITABANI_H
#define VERITABANI_H

#include <QObject>
#include <QList>
#include <QtSql>

#include "kutuphane_global.h"
#include "alici.h"
#include "gonderici.h"
#include "sehir.h"
#include "sube.h"
#include "urun.h"
#include "merkezsube.h"

class KUTUPHANESHARED_EXPORT veritabani : public QObject
{
    Q_OBJECT

private:

    explicit veritabani(QObject *parent = 0);
    static veritabani *veritabaniPtr;
    QSqlDatabase vt;


signals:

public slots:
    void aliciEkle(alici *value);
    void gondericiEkle(gonderici *value);
    void sehirEkle(sehir *value);
    void subeEkle(sube *value);
    void urunEkle(urun *value);
    void merkezEkle(merkezSube *value);

    void aliciSil(alici *value);
    void gondericiSil(gonderici *value);
    void sehirSil(sehir *value);
    void subeSil(sube *value);
    void urunSil(urun *value);
    void merkezSil(merkezSube *value);

    void aliciGuncelle(alici *value);
    void gondericiGuncelle(gonderici *value);
    void sehirGuncelle(sehir *value);
    void subeGuncelle(sube *value);
    void urunGuncelle(urun *value);
    void merkezGuncelle(merkezSube *value);

    alici *aliciKodAra(QString value);
    QList<alici *> aliciAdAra(QString value);
    QList<alici *> aliciSoyadAra(QString value);
    QList<alici *> aliciTumuAra();
    QList<alici *> aliciAdSoyadSoyadAra(QString value1,QString value2);

    gonderici * gondericiKodAra(QString value);
    QList<gonderici *> gondericiAdAra(QString value);
    QList<gonderici *> gondericiSoyadAra(QString value);
    QList<gonderici *> gondericiTumuAra();
    QList<gonderici *> gondericiAdSoyadAra(QString value1, QString value2);

    sube *subeKodAra(QString value);
    QList<sube *> subeAdAra(QString value);
    QList<sube *> subeSehirAra(QString value);
    QList<sube *> subeTumuAra();

    QList<urun *> urunKodAra(QString value);
    QList<urun *> urunGondericiAra(QString value);
    QList<urun *> urunAliciAra(QString value);
    QList<urun *> urunTumuAra();

    sehir *sehirAra (QString value);
    sehir *sehirKodAra(QString value);
    QList<sehir *> sehirTumuAra();

    merkezSube *merkezSubeKodAra(QString merkezkod);
    QList<merkezSube *> merkezSubeTumuAra();
    QList<sehir *> merkezSubeSehirAra(QString value);

    sehir *urunKodundanAliciSubeSehire(QString urunKod);
    sehir *urunKodundanGondericiSubeSehire(QString urunKod);

    QList <sehir *> duzergah(QString value);

public:

    static veritabani *getVeritabani();

};

#endif // VERITABANI_H
