#include "veritabani.h"
#include <QVariant>
#include <QPair>
#include "hesap.h"

veritabani* veritabani::veritabaniPtr = NULL;


veritabani::veritabani(QObject *parent) : QObject(parent)
{
    vt = QSqlDatabase::addDatabase("QSQLITE");
    vt.setDatabaseName("datebase.db");


    if (vt.open()) {

        vt.exec("create table if not exists alici(kod text, ad text,soyad text, adres text, tel text, mail text, subekod text, urunkod text, gondericikod text)");

        vt.exec("create table if not exists gonderici(kod text, ad text,soyad text,adres text,tel text,mail text, subekod text,urunkod text)");

        vt.exec("create table if not exists sehir(kod text,ad text,xkoordinat number,ykoordinat number)");

        vt.exec("create table if not exists sube(kod text,ad text,tel text,mail text, sehirkod text)");

        vt.exec("create table if not exists urun(kod text,tip text, agirlik number,hacim number,fiyat double, alicikod text, gondericikod text,durum int)");

        vt.exec("create table if not exists merkezsube (kod text,durum int,subekod text)");
    }
}

void veritabani::aliciEkle(alici *value)
{

    QSqlQuery ekle;
    ekle.prepare("insert into alici(kod,ad,soyad,adres,tel,mail,subekod,urunkod,gondericikod) values(:kod,:ad,:soyad,:adres,:tel,:mail,:subekod,:urunkod,:gondericikod)");
    ekle.bindValue(0,value->getKodStr());
    ekle.bindValue(1,value->getAdStr());
    ekle.bindValue(2,value->getSoyadStr());
    ekle.bindValue(3,value->getAdresStr());
    ekle.bindValue(4,value->getAdresStr());
    ekle.bindValue(5,value->getMailStr());
    ekle.bindValue(6,value->getAlinanSube());
    ekle.bindValue(7,value->getAlinanUrun());
    ekle.bindValue(8,value->getGonderMusteri());

    ekle.exec();

}

void veritabani::gondericiEkle(gonderici *value)
{
    QSqlQuery ekle;
    ekle.prepare("insert into gonderici(kod,ad,soyad,adres,tel,mail,subekod,urunkod) values (:kod,:ad,:soyad,:adres,:tel,:mail,:subekod,:urunkod)");

    ekle.bindValue(0,value->getKodStr());
    ekle.bindValue(1,value->getAdStr());
    ekle.bindValue(2,value->getSoyadStr());
    ekle.bindValue(3,value->getAdresStr());
    ekle.bindValue(4,value->getTelStr());
    ekle.bindValue(5,value->getMailStr());
    ekle.bindValue(6,value->getGondericiSube());

    ekle.exec();

}

void veritabani::sehirEkle(sehir *value)
{
    QSqlQuery ekle;
    ekle.prepare("insert into sehir(kod,ad,xkoordinat,ykoordinat) values (?,?,?,?)");

    ekle.bindValue(0,value->getKodStr());
    ekle.bindValue(1,value->getAdiStr());
    ekle.bindValue(2,value->getXKoordinatDbl());
    ekle.bindValue(3,value->getYKoordinatDbl());

    ekle.exec();

}

void veritabani::subeEkle(sube *value)
{
    QSqlQuery ekle;
    ekle.prepare("insert into sube(kod ,ad, tel, mail, sehirkod) values (:kod,:ad,:tel,:mail,:sehirkod)");

    ekle.bindValue(0,value->getKodStr());
    ekle.bindValue(1,value->getAdiStr());
    ekle.bindValue(2,value->getTelStr());
    ekle.bindValue(3,value->getMailStr());
    ekle.bindValue(4,value->getSubeSehir());

    ekle.exec();
}

void veritabani::urunEkle(urun *value)
{
    QSqlQuery ekle;
    ekle.prepare("insert into urun(kod,tip,agirlik,hacim,fiyat,alicikod,gondericikod,durum) values (:kod,:tip,:agirlik,:hacim,:fiyat,:alicikod,:gondericikod,:durum)");

    ekle.bindValue(0,value->getKodStr());
    ekle.bindValue(1,value->getTipStr());
    ekle.bindValue(2,value->getAgirliDbl());
    ekle.bindValue(3,value->getHacimDbl());
    ekle.bindValue(4,value->getFiyatDbl());
    ekle.bindValue(5,value->getAliciMusteri());
    ekle.bindValue(6,value->getGondericiMusteri());
    ekle.bindValue(7,value->getDurum());

    ekle.exec();
}

void veritabani::merkezEkle(merkezSube *value)
{
    QSqlQuery ekle;
    ekle.prepare("insert into merkezsube(kod,durum,subekod) values (:kod,:durum,:subekod)");

    ekle.bindValue(0,value->getKod());
    ekle.bindValue(1,value->getDurum());
    ekle.bindValue(2,value->getSubeKod());

    ekle.exec();
}

void veritabani::aliciSil(alici *value)
{
    QSqlQuery sil;
    sil.prepare("delete from alici where kod=?");

    sil.bindValue(0,value->getKodStr());

    sil.exec();
}

void veritabani::gondericiSil(gonderici *value)
{
    QSqlQuery sil;
    sil.prepare("delete from gonderici where kod = ?");
    sil.bindValue(0,value->getKodStr());
    sil.exec();

    sil.prepare("delete from urun where gondericikod=?");
    sil.bindValue(0,value->getKodStr());
    sil.exec();
}

void veritabani::sehirSil(sehir *value)
{

    QSqlQuery sil;
    sil.prepare("delete from sehir where kod = ?");
    sil.bindValue(0,value->getKodStr());
    sil.exec();
}

void veritabani::subeSil(sube *value)
{
    QSqlQuery sil;
    sil.prepare("delete from sube where kod = ?");
    sil.bindValue(0,value->getKodStr());
    sil.exec();
}

void veritabani::urunSil(urun *value)
{
    QSqlQuery sil;
    sil.prepare("delete from urun where kod = ?");
    sil.bindValue(0,value->getKodStr());
    sil.exec();
}

void veritabani::merkezSil(merkezSube *value)
{
    QSqlQuery sil;
    sil.prepare("delete from merkezsube where kod = ?");
    sil.bindValue(0,value->getKod());
    sil.exec();
}

void veritabani::aliciGuncelle(alici *value)
{
    QSqlQuery guncelle;
    guncelle.prepare("update alici set ad = ?, soyad = ? , adres = ?,tel = ?,mail = ? where kod =?");
    guncelle.bindValue(0,value->getAdStr());
    guncelle.bindValue(1,value->getSoyadStr());
    guncelle.bindValue(2,value->getAdresStr());
    guncelle.bindValue(3,value->getTelStr());
    guncelle.bindValue(4,value->getMailStr());
    guncelle.bindValue(5,value->getKodStr());
    guncelle.exec();

}

void veritabani::gondericiGuncelle(gonderici *value)
{
    QSqlQuery guncelle;
    guncelle.prepare("update gonderici set ad = ?, soyad = ? , adres = ?,tel = ?,mail = ? ,subekod = ?, urunkod = ? where kod =?");
    guncelle.bindValue(0,value->getAdStr());
    guncelle.bindValue(1,value->getSoyadStr());
    guncelle.bindValue(2,value->getAdresStr());
    guncelle.bindValue(3,value->getTelStr());
    guncelle.bindValue(4,value->getMailStr());
    guncelle.bindValue(7,value->getKodStr());
    guncelle.bindValue(5,value->getGondericiSube());
    guncelle.bindValue(6,value->getGonderilenUrun());
    guncelle.exec();

}

void veritabani::sehirGuncelle(sehir *value)
{
    QSqlQuery guncelle;
    guncelle.prepare("update sehir set ad = ?,xkoordinat =?,ykoordinat = ? where kod = ?");
    guncelle.bindValue(0,value->getAdiStr());
    guncelle.bindValue(1,value->getXKoordinatDbl());
    guncelle.bindValue(2,value->getYKoordinatDbl());
    guncelle.bindValue(3,value->getKodStr());
    guncelle.exec();
}

void veritabani::subeGuncelle(sube *value)
{
    QSqlQuery guncelle;
    guncelle.prepare("update sube set ad = ?,tel=?,mail=? where kod =?");
    guncelle.bindValue(0,value->getAdiStr());
    guncelle.bindValue(1,value->getTelStr());
    guncelle.bindValue(2,value->getMailStr());
    guncelle.bindValue(3,value->getKodStr());
    guncelle.exec();
}

void veritabani::urunGuncelle(urun *value)
{
    QSqlQuery guncelle;
    guncelle.prepare("update urun set tip =?,agirlik =?,hacim=?,alicikod =?,gondericikod=?,durum=? where kod=?");
    guncelle.bindValue(0,value->getTipStr());
    guncelle.bindValue(1,value->getAgirliDbl());
    guncelle.bindValue(2,value->getHacimDbl());
    guncelle.bindValue(3,value->getAliciMusteri());
    guncelle.bindValue(4,value->getGondericiMusteri());
    guncelle.bindValue(5,value->getDurum());
    guncelle.bindValue(6,value->getKodStr());
    guncelle.exec();
}

void veritabani::merkezGuncelle(merkezSube *value)
{
    QSqlQuery guncelle;
    guncelle.prepare("update merkezsube set durum =?, subekod = ? where kod = ?");
    guncelle.bindValue(0,value->getDurum());
    guncelle.bindValue(1,value->getSubeKod());
    guncelle.bindValue(2,value->getKod());

    guncelle.exec();
}

alici *veritabani::aliciKodAra(QString value)
{
    QSqlQuery ara;
    ara.prepare("SELECT * FROM alici where kod =?");

    ara.bindValue(0,value);
    ara.exec();

    alici *bul = new alici(this);
    while (ara.next()) {

        bul->setAdStr(ara.value(1).toString());
        bul->setSoyadStr(ara.value(2).toString());
        bul->setAdresStr(ara.value(3).toString());
        bul->setTelStr(ara.value(4).toString());
        bul->setMailStr(ara.value(5).toString());
        bul->setAlinanUrun(ara.value(8).toString());
        bul->setGonderMusteri(ara.value(7).toString());
        bul->setAlinanSube(ara.value(6).toString());
        bul->setKodStr(ara.value(0).toString());
    }
    return bul;
}

QList<alici *> veritabani::aliciAdAra(QString value)
{
    QSqlQuery ara;
    ara.prepare("SELECT * FROM alici where ad =?");

    ara.bindValue(0,value);
    ara.exec();

    QList<alici *> sonuc;
    while (ara.next()) {
        alici *bul = new alici(this);

        bul->setAdStr(ara.value(1).toString());
        bul->setSoyadStr(ara.value(2).toString());
        bul->setAdresStr(ara.value(3).toString());
        bul->setTelStr(ara.value(4).toString());
        bul->setMailStr(ara.value(5).toString());
        bul->setAlinanUrun(ara.value(8).toString());
        bul->setGonderMusteri(ara.value(7).toString());
        bul->setAlinanSube(ara.value(6).toString());
        bul->setKodStr(ara.value(0).toString());
        sonuc.append(bul);
    }

    return sonuc;

}


QList<alici *> veritabani::aliciSoyadAra(QString value)
{
    QSqlQuery ara;
    ara.prepare("SELECT * FROM alici where soyad =?");

    ara.bindValue(0,value);
    ara.exec();

    QList<alici *> sonuc;
    while (ara.next()) {
        alici *bul = new alici(this);

        bul->setAdStr(ara.value(1).toString());
        bul->setSoyadStr(ara.value(2).toString());
        bul->setAdresStr(ara.value(3).toString());
        bul->setTelStr(ara.value(4).toString());
        bul->setMailStr(ara.value(5).toString());
        bul->setAlinanUrun(ara.value(8).toString());
        bul->setGonderMusteri(ara.value(7).toString());
        bul->setAlinanSube(ara.value(6).toString());
        bul->setKodStr(ara.value(0).toString());
        sonuc.append(bul);
    }

    return sonuc;
}

QList<alici *> veritabani::aliciTumuAra()
{
    QSqlQuery ara;
    ara.prepare("SELECT * FROM alici");
    ara.exec();

    QList<alici *> sonuc;
    while(ara.next()){
        alici *bul = new alici(this);

        bul->setKodStr(ara.value(0).toString());
        bul->setAdStr(ara.value(1).toString());
        bul->setSoyadStr(ara.value(2).toString());
        bul->setAdresStr(ara.value(3).toString());
        bul->setTelStr(ara.value(4).toString());
        bul->setMailStr(ara.value(5).toString());
        bul->setAlinanUrun(ara.value(6).toString());
        bul->setGonderMusteri(ara.value(7).toString());
        bul->setAlinanSube(ara.value(8).toString());

        sonuc.append(bul);
    }
    return sonuc;
}

QList<alici *> veritabani::aliciAdSoyadSoyadAra(QString value1, QString value2)
{
    QSqlQuery ara;
    ara.prepare("SELECT * FROM alici where ad =? and soyad=?");

    ara.bindValue(0,value1);
    ara.bindValue(1,value2);
    ara.exec();

    QList<alici *> sonuc;
    while (ara.next()) {
        alici *bul = new alici(this);

        bul->setAdStr(ara.value(1).toString());
        bul->setSoyadStr(ara.value(2).toString());
        bul->setAdresStr(ara.value(3).toString());
        bul->setTelStr(ara.value(4).toString());
        bul->setMailStr(ara.value(5).toString());
        bul->setAlinanUrun(ara.value(8).toString());
        bul->setGonderMusteri(ara.value(7).toString());
        bul->setAlinanSube(ara.value(6).toString());
        bul->setKodStr(ara.value(0).toString());
        sonuc.append(bul);
    }

    return sonuc;

}

gonderici *veritabani::gondericiKodAra(QString value)
{
    QSqlQuery ara;
    ara.prepare("select ad,soyad,adres,tel,mail,urunkod,subekod,kod from gonderici where kod = ?");

    ara.bindValue(0,value);
    ara.exec();

    gonderici *bul = new gonderici(this);
    while (ara.next()) {
        bul->setAdStr(ara.value(0).toString());
        bul->setSoyadStr(ara.value(1).toString());
        bul->setAdresStr(ara.value(2).toString());
        bul->setTelStr(ara.value(3).toString());
        bul->setMailStr(ara.value(4).toString());
        bul->setGonderilenUrun(ara.value(5).toString());
        bul->setGondericiSube(ara.value(6).toString());
        bul->setKodStr(ara.value(7).toString());
    }

    return bul;
}

QList<gonderici *> veritabani::gondericiAdAra(QString value)
{
    QSqlQuery ara;
    ara.prepare("select ad,soyad,adres,tel,mail,urunkod,subekod,kod from gonderici where ad =?");

    ara.bindValue(0,value);
    ara.exec();

    QList<gonderici *> sonuc;
    while (ara.next()) {
        gonderici *bul = new gonderici(this);

        bul->setAdStr(ara.value(0).toString());
        bul->setSoyadStr(ara.value(1).toString());
        bul->setAdresStr(ara.value(2).toString());
        bul->setTelStr(ara.value(3).toString());
        bul->setMailStr(ara.value(4).toString());
        bul->setGonderilenUrun(ara.value(5).toString());
        bul->setGondericiSube(ara.value(6).toString());
        bul->setKodStr(ara.value(7).toString());
        sonuc.append(bul);
    }
    return sonuc;
}

QList<gonderici *> veritabani::gondericiSoyadAra(QString value)
{
    QSqlQuery ara;
    ara.prepare("select ad,soyad,adres,tel,mail,urunkod,subekod from gonderici where soyad =?");

    ara.bindValue(0,value);
    ara.exec();

    QList<gonderici *> sonuc;
    while (ara.next()) {
        gonderici *bul = new gonderici(this);

        bul->setAdStr(ara.value(0).toString());
        bul->setSoyadStr(ara.value(1).toString());
        bul->setAdresStr(ara.value(2).toString());
        bul->setTelStr(ara.value(3).toString());
        bul->setMailStr(ara.value(4).toString());
        bul->setGonderilenUrun(ara.value(5).toString());
        bul->setGondericiSube(ara.value(6).toString());
        sonuc.append(bul);
    }

    return sonuc;
}

QList<gonderici *> veritabani::gondericiTumuAra()
{
    QSqlQuery ara;
    ara.prepare("SELECT * FROM gonderici ");
    ara.exec();
    QList<gonderici *> sonuc;
    while (ara.next()) {
        gonderici *bul = new gonderici(this);

        bul->setKodStr(ara.value(0).toString());
        bul->setAdStr(ara.value(1).toString());
        bul->setSoyadStr(ara.value(2).toString());
        bul->setAdresStr(ara.value(3).toString());
        bul->setTelStr(ara.value(4).toString());
        bul->setMailStr(ara.value(5).toString());
        bul->setGonderilenUrun(ara.value(7).toString());
        bul->setGondericiSube(ara.value(6).toString());
        sonuc.append(bul);
    }

    return sonuc;

}

QList<gonderici *> veritabani::gondericiAdSoyadAra(QString value1, QString value2)
{
    QSqlQuery ara;
    ara.prepare("select ad,soyad,adres,tel,mail,urunkod,subekod,kod from gonderici where ad=? and soyad=?");

    ara.bindValue(0,value1);
    ara.bindValue(1,value2);
    ara.exec();

    QList<gonderici *> sonuc;
    while (ara.next()) {
        gonderici *bul = new gonderici(this);

        bul->setAdStr(ara.value(0).toString());
        bul->setSoyadStr(ara.value(1).toString());
        bul->setAdresStr(ara.value(2).toString());
        bul->setTelStr(ara.value(3).toString());
        bul->setMailStr(ara.value(4).toString());
        bul->setGonderilenUrun(ara.value(5).toString());
        bul->setGondericiSube(ara.value(6).toString());
        bul->setKodStr(ara.value(7).toString());
        sonuc.append(bul);
    }
    return sonuc;
}

sube *veritabani::subeKodAra(QString value)
{
    QSqlQuery ara;
    ara.prepare("select ad,tel,mail,sehirkod from sube where kod=?");

    ara.bindValue(0,value);
    ara.exec();

    sube *bul = new sube(this);
    while (ara.next()) {

        bul->setAdiStr(ara.value(0).toString());
        bul->setTelStr(ara.value(1).toString());
        bul->setMailStr(ara.value(2).toString());
        bul->setSubeSehir(ara.value(3).toString());
    }

    return bul;
}

QList<sube *> veritabani::subeAdAra(QString value)
{
    QSqlQuery ara;
    ara.prepare("select ad,tel,mail,sehirkod,kod from sube where ad=?");

    ara.bindValue(0,value);
    ara.exec();

    QList<sube *> sonuc;
    while (ara.next()) {
        sube *bul = new sube(this);

        bul->setAdiStr(ara.value(0).toString());
        bul->setTelStr(ara.value(1).toString());
        bul->setMailStr(ara.value(2).toString());
        bul->setSubeSehir(ara.value(3).toString());
        bul->setKodStr(ara.value(4).toString());

        sonuc.append(bul);
    }
    return sonuc;
}

QList<sube *> veritabani::subeSehirAra(QString value)
{
    QSqlQuery ara;
    ara.prepare("select ad,tel,mail,sehirkod from sube where sehirkod=?");

    ara.bindValue(0,value);
    ara.exec();

    QList<sube *> sonuc;
    while (ara.next()) {
        sube *bul = new sube(this);

        bul->setAdiStr(ara.value(0).toString());
        bul->setTelStr(ara.value(1).toString());
        bul->setMailStr(ara.value(2).toString());
        bul->setSubeSehir(ara.value(3).toString());

        sonuc.append(bul);
    }
    return sonuc;
}

QList<sube *> veritabani::subeTumuAra()
{
    QSqlQuery ara;
    ara.prepare("select * from sube");
    ara.exec();

    QList<sube *> sonuc;
    while (ara.next()) {
        sube *bul = new sube(this);

        bul->setKodStr(ara.value(0).toString());
        bul->setAdiStr(ara.value(1).toString());
        bul->setTelStr(ara.value(2).toString());
        bul->setMailStr(ara.value(3).toString());
        bul->setSubeSehir(ara.value(4).toString());

        sonuc.append(bul);
    }
    return sonuc;
}

sehir *veritabani::sehirAra(QString value)
{
    QSqlQuery ara;
    ara.prepare("select xkoordinat,ykoordinat,ad,kod from sehir where ad = ?");

    ara.bindValue(0,value);
    ara.exec();

    sehir *sonuc = new sehir(this);
    while (ara.next()) {
        sonuc->setXKoordinatDbl(ara.value(0).toDouble());
        sonuc->setYKoordinatDbl(ara.value(1).toDouble());
        sonuc->setAdiStr(ara.value(2).toString());
        sonuc->setKodStr(ara.value(3).toString());
    }
    return sonuc;
}

sehir *veritabani::sehirKodAra(QString value)
{
    QSqlQuery ara;
    ara.prepare("select xkoordinat,ykoordinat,ad,kod from sehir where kod = ?");

    ara.bindValue(0,value);
    ara.exec();
    sehir *sonuc = new sehir(this);
    while (ara.next()) {
        sonuc->setXKoordinatDbl(ara.value(0).toDouble());
        sonuc->setYKoordinatDbl(ara.value(1).toDouble());
        sonuc->setAdiStr(ara.value(2).toString());
        sonuc->setKodStr(ara.value(3).toString());
    }
    return sonuc;
}

QList<sehir *> veritabani::sehirTumuAra()
{
    QSqlQuery ara;
    ara.prepare("select * from sehir");
    ara.exec();
    QList<sehir *> sonuc;
    while (ara.next()) {
        sehir *ekle = new sehir(this);
        ekle->setKodStr(ara.value(0).toString());
        ekle->setAdiStr(ara.value(1).toString());
        ekle->setXKoordinatDbl(ara.value(2).toDouble());
        ekle->setYKoordinatDbl(ara.value(3).toDouble());
        sonuc.append(ekle);
    }
    return sonuc;
}

QList<urun *> veritabani::urunKodAra(QString value)
{
    QSqlQuery ara;
    ara.prepare("select tip,agirlik,hacim,fiyat,alicikod,gondericikod, kod from urun where kod =?");
    ara.bindValue(0,value);
    ara.exec();

    QList<urun *> sonuc;
    while (ara.next()) {
        urun *bul = new urun(this);

        bul->setTipStr(ara.value(0).toString());
        bul->setAgirliDbl(ara.value(1).toDouble());
        bul->setHacimDbl(ara.value(2).toDouble());
        bul->setFiyatDbl(ara.value(3).toDouble());
        bul->setAliciMusteri(ara.value(4).toString());
        bul->setGondericiMusteri(ara.value(5).toString());
        bul->setKodStr(ara.value(6).toString());

        sonuc.append(bul);
    }
    return sonuc;
}

QList<urun *> veritabani::urunGondericiAra(QString value)
{
    QSqlQuery ara;
    ara.prepare("select tip,agirlik,hacim,fiyat,alicikod,gondericikod,durum,kod from urun where gondericikod = ?");
    ara.bindValue(0,value);
    ara.exec();

    QList<urun *> sonuc;

    while(ara.next()){
        urun *bul = new urun(this);

        bul->setTipStr(ara.value(0).toString());
        bul->setAgirliDbl(ara.value(1).toDouble());
        bul->setHacimDbl(ara.value(2).toDouble());
        bul->setFiyatDbl(ara.value(3).toDouble());
        bul->setAliciMusteri(ara.value(4).toString());
        bul->setGondericiMusteri(ara.value(5).toString());
        bul->setDurum(ara.value(6).toInt());
        bul->setKodStr(ara.value(7).toString());

        sonuc.append(bul);
    }
    return sonuc;
}

QList<urun *> veritabani::urunAliciAra(QString value)
{
    QSqlQuery ara;
    ara.prepare("select tip,agiligi,hacim,fiyat,alicikod,gondericikod,durum from urun where alicikod = ?");
    ara.bindValue(0,value);
    ara.exec();

    QList<urun *> sonuc;

    while(ara.next()){
        urun *bul = new urun(this);

        bul->setTipStr(ara.value(0).toString());
        bul->setAgirliDbl(ara.value(1).toDouble());
        bul->setHacimDbl(ara.value(2).toDouble());
        bul->setFiyatDbl(ara.value(3).toDouble());
        bul->setAliciMusteri(ara.value(4).toString());
        bul->setGondericiMusteri(ara.value(5).toString());
        bul->setDurum(ara.value(7).toInt());

        sonuc.append(bul);
    }
    return sonuc;
}

QList<urun *> veritabani::urunTumuAra()
{
    QSqlQuery ara;
    ara.prepare("select kod,tip,agirlik,hacim,fiyat,alicikod,gondericikod,durum from urun");

    ara.exec();

    QList<urun *> sonuc;
    while (ara.next()) {
        urun *bul = new urun(this);

        bul->setKodStr(ara.value(0).toString());
        bul->setTipStr(ara.value(1).toString());
        bul->setAgirliDbl(ara.value(2).toDouble());
        bul->setHacimDbl(ara.value(3).toDouble());
        bul->setFiyatDbl(ara.value(4).toDouble());
        bul->setAliciMusteri(ara.value(5).toString());
        bul->setGondericiMusteri(ara.value(6).toString());
        bul->setDurum(ara.value(7).toInt());


        sonuc.append(bul);
    }
    return sonuc;
}

merkezSube *veritabani::merkezSubeKodAra(QString merkezkod)
{
    QSqlQuery ara;
    ara.prepare("select durum,subekod,kod from merkezsube where kod = ?");
    ara.bindValue(0,merkezkod);
    ara.exec();

    merkezSube *bul = new merkezSube(this);

    while (ara.next()) {
        bul->setDurum(ara.value(0).toInt());
        bul->setSubeKod(ara.value(1).toString());
        bul->setKod(ara.value(2).toString());

    }
    return bul;
}

QList<merkezSube *> veritabani::merkezSubeTumuAra()
{
    QSqlQuery ara;
    ara.prepare("select * from merkezsube");
    ara.exec();

    QList<merkezSube *> sonuc;

    while (ara.next()) {
        merkezSube *bul = new merkezSube(this);
        bul->setKod(ara.value(0).toString());
        bul->setDurum(ara.value(1).toInt());
        bul->setSubeKod(ara.value(2).toString());
        sonuc.append(bul);
    }
    return sonuc;
}

QList<sehir *> veritabani::merkezSubeSehirAra(QString value)
{
    QList<sehir *> sonuc;
    sonuc.append(sehirKodAra(subeKodAra(merkezSubeKodAra(value)->getSubeKod())->getSubeSehir()));
    return sonuc;
}

sehir *veritabani::urunKodundanAliciSubeSehire(QString urunKod)
{
   return sehirKodAra(subeKodAra(aliciKodAra(urunKodAra(urunKod).first()->getAliciMusteri())->getAlinanSube())->getSubeSehir());
}

sehir *veritabani::urunKodundanGondericiSubeSehire(QString urunKod)
{
    return sehirKodAra(subeAdAra(gondericiKodAra(urunKodAra(urunKod).first()->getGondericiMusteri())->getGondericiSube()).first()->getSubeSehir());
}

QList<sehir *> veritabani::duzergah(QString value)
{
    hesap* a;
    QList<sehir *> veri = a->urunDuzergahOlustur(value);
    return veri;
}


veritabani *veritabani::getVeritabani()
{
    if(veritabaniPtr == NULL) {
        veritabaniPtr = new veritabani;
    }
    return veritabaniPtr;
}
