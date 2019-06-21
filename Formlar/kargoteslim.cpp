#include "kargoteslim.h"
#include "ui_kargoteslim.h"
#include "kargotakip.h"
#include "QMessageBox"
#include <gondericiara.h>
#include "ui_gondericiara.h"
#include <QString>

kargoTeslim::kargoTeslim(gonderici *a, alici *b, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kargoTeslim)
{
    ui->setupUi(this);
    if(b != NULL || a != NULL){
        if(b == NULL){
            ui->lnMusteriKodu->setText(a->getKodStr());
        }
        if(a == NULL){
            ui->lnMusteriKodu->setText(b->getKodStr());
        }
    }

    QList<sube *> subeGelen = veritabani::getVeritabani()->subeTumuAra();
    if(subeGelen.count() != 0){
        for(int i = 0 ; i < subeGelen.count(); i++){
            ui->cmbxSubeList->addItem(subeGelen[i]->getAdiStr());
        }
    }

    QPalette* palette = new QPalette();
    palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap(":/background/background.png")))));
    setPalette(*palette);

}

kargoTeslim::~kargoTeslim()
{
    delete ui;
}

void kargoTeslim::on_btnGeri_clicked()
{
    close();
    KargoTakip* s = new KargoTakip();
    s->show();
}

void kargoTeslim::on_btnKaydet_clicked()
{
    urun *urunEkle = new urun;
    alici *ekle =new alici;
    if(veritabani::getVeritabani()->aliciTumuAra().count() == 0){
        ekle->setAdStr(ui->lnAd->text());
        ekle->setSoyadStr(ui->lnSoyad->text());
        ekle->setMailStr(ui->lnMail->text());
        ekle->setTelStr(ui->lnCepNo->text());
        ekle->setAdresStr(ui->lnAdres->text());
        ekle->setAlinanSube(ui->cmbxSubeList->currentText());
        ekle->setKodStr("200000");
    }else{
        ekle->setAdStr(ui->lnAd->text());
        ekle->setSoyadStr(ui->lnSoyad->text());
        ekle->setMailStr(ui->lnMail->text());
        ekle->setTelStr(ui->lnCepNo->text());
        ekle->setAdresStr(ui->lnAdres->text());
        ekle->setAlinanSube(ui->cmbxSubeList->currentText());
        ekle->setKodStr(QString::number(veritabani::getVeritabani()->aliciTumuAra().last()->getKodStr().toInt() + 1));
    }

    if(veritabani::getVeritabani()->urunTumuAra().count() == 0){
        urunEkle->setTipStr(ui->lnUrunTipi->text());
        urunEkle->setAgirliDbl(ui->lnAgirligi->text().toDouble());
        urunEkle->setHacimDbl(ui->lnHacmi->text().toDouble());
        urunEkle->setKodStr("300000");
        urunEkle->setAliciMusteri(ekle->getKodStr());
        urunEkle->setGondericiMusteri(ui->lnMusteriKodu->text());
        urunEkle->setDurum(1);
        urunEkle->setFiyatDbl(ui->lnHacmi->text().toDouble() / 3000 * ui->lnBirimFiyat->text().toDouble());
    }else{
        urunEkle->setTipStr(ui->lnUrunTipi->text());
        urunEkle->setAgirliDbl(ui->lnAgirligi->text().toDouble());
        urunEkle->setHacimDbl(ui->lnHacmi->text().toDouble());
        urunEkle->setKodStr(QString::number(veritabani::getVeritabani()->urunTumuAra().last()->getKodStr().toInt() + 1));
        urunEkle->setAliciMusteri(ekle->getKodStr());
        urunEkle->setGondericiMusteri(ui->lnMusteriKodu->text());
        urunEkle->setDurum(1);
        urunEkle->setFiyatDbl(ui->lnHacmi->text().toDouble() / 3000 * ui->lnBirimFiyat->text().toDouble());
    }

    gonderici *sonuc = veritabani::getVeritabani()->gondericiKodAra(ui->lnMusteriKodu->text());
    sonuc->setGonderilenUrun(urunEkle->getKodStr());

    ekle->setGonderMusteri(ui->lnMusteriKodu->text());
    ekle->setAlinanUrun(urunEkle->getKodStr());

    veritabani::getVeritabani()->aliciEkle(ekle);
    veritabani::getVeritabani()->gondericiGuncelle(sonuc);
    veritabani::getVeritabani()->urunEkle(urunEkle);


    if(ui->lnHacmi->text().toDouble()/3 > ui->lnAgirligi->text().toDouble()){
        double fiyat = ui->lnHacmi->text().toDouble()/3*ui->lnBirimFiyat->text().toDouble();
        QMessageBox::information(this,"Tebrikler","Bilgileriniz Kaydedildi.Anasayfaya Yönlendiriliyorsunuz.Kargo Ücreti:"+QString::number(fiyat));

    }else if(ui->lnAgirligi->text().toDouble() > ui->lnHacmi->text().toDouble()/3){
        double fiyat = ui->lnAgirligi->text().toDouble()*ui->lnBirimFiyat->text().toDouble();
        QMessageBox::information(this,"Tebrikler","Bilgileriniz Kaydedildi.Anasayfaya Yönlendiriliyorsunuz.Kargo Ücreti"+QString::number(fiyat));
    }
    close();
    KargoTakip* a = new KargoTakip();
    a->show();
}
