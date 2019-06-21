#include "gondericiara.h"
#include "ui_gondericiara.h"
#include "kargotakip.h"
#include <QString>
#include <QMessageBox>
#include "kargoteslim.h"
#include "kargotakip.h"
#include "guzergaholustur.h"

gondericiAra::gondericiAra(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gondericiAra)
{
    ui->setupUi(this);
    QPalette* palette = new QPalette();
    palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap(":/background/background.png")))));
    setPalette(*palette);
}

gondericiAra::~gondericiAra()
{
    delete ui;
}

void gondericiAra::on_btnAnaSayfa_clicked()
{
    close();
    KargoTakip* s = new KargoTakip();
    s->show();
}

void gondericiAra::on_btnKodAra_clicked()
{
    if(ui->rBtnGondericiAra->isChecked()){
        gonderici* bul = veritabani::getVeritabani()->gondericiKodAra(ui->lnMusteriKodu->text());

        if(bul->getKodStr()== ""){
            QMessageBox::information(this,"Bilgilendirme","Aradığınız Koda Ait Müşteri Bilgisi Bulunamadı.");
        }
        else{
            int c = ui->tblListele->columnCount();
            for (int i = 0; i < c; i++) {
                ui->tblListele->removeColumn(0);
            }
            ui->tblListele->setColumnCount(8);
            QStringList sutunlar;
            sutunlar.append("Kod");
            sutunlar.append("Ad");
            sutunlar.append("Soyad");
            sutunlar.append("Adres");
            sutunlar.append("Tel");
            sutunlar.append("Mail");
            sutunlar.append("Şube");
            sutunlar.append("En Son Ürün");

            ui->tblListele->setHorizontalHeaderLabels(sutunlar);
            ui->tblListele->setRowCount(1);
            QTableWidgetItem *kodHucresi = new QTableWidgetItem();
            QTableWidgetItem *adHucresi = new QTableWidgetItem();
            QTableWidgetItem *soyadHucresi = new QTableWidgetItem();
            QTableWidgetItem *adresHucresi = new QTableWidgetItem();
            QTableWidgetItem *telHucresi = new QTableWidgetItem();
            QTableWidgetItem *mailHucresi = new QTableWidgetItem();
            QTableWidgetItem *subeHucresi = new QTableWidgetItem();
            QTableWidgetItem *gonderilenUrunHucresi = new QTableWidgetItem();


            kodHucresi->setText(bul->getKodStr());
            adHucresi->setText(bul->getAdStr());
            soyadHucresi->setText(bul->getSoyadStr());
            adresHucresi->setText(bul->getAdresStr());
            telHucresi->setText(bul->getTelStr());
            mailHucresi->setText(bul->getMailStr());
            subeHucresi->setText(bul->getGondericiSube());
            gonderilenUrunHucresi->setText(bul->getGonderilenUrun());

            ui->tblListele->setItem(0,0,kodHucresi);
            ui->tblListele->setItem(0,1,adHucresi);
            ui->tblListele->setItem(0,2,soyadHucresi);
            ui->tblListele->setItem(0,3,adresHucresi);
            ui->tblListele->setItem(0,4,telHucresi);
            ui->tblListele->setItem(0,5,mailHucresi);
            ui->tblListele->setItem(0,6,subeHucresi);
            ui->tblListele->setItem(0,7,gonderilenUrunHucresi);

        }
    }

    if (ui->rBtnAliciAra->isChecked()) {
        alici* bul = veritabani::getVeritabani()->aliciKodAra(ui->lnMusteriKodu->text());

        if (bul->getKodStr() == "") {
            QMessageBox::information(this,"Bilgilendirme","Aradığınız Koda Ait Müşteri Bilgisi Bulunamadı.");
        }
        else{
            int c = ui->tblListele->columnCount();
            for (int i = 0; i < c; i++) {
                ui->tblListele->removeColumn(0);
            }
            ui->tblListele->setColumnCount(9);
            QStringList sutunlar;
            sutunlar.append("Kod");
            sutunlar.append("Ad");
            sutunlar.append("Soyad");
            sutunlar.append("Adres");
            sutunlar.append("Tel");
            sutunlar.append("Mail");
            sutunlar.append("Şube");
            sutunlar.append("Alınan Ürün");
            sutunlar.append("Gönderici Kodu");


            ui->tblListele->setHorizontalHeaderLabels(sutunlar);


            ui->tblListele->setRowCount(1);
            QTableWidgetItem *kodHucresi = new QTableWidgetItem();
            QTableWidgetItem *adHucresi = new QTableWidgetItem();
            QTableWidgetItem *soyadHucresi = new QTableWidgetItem();
            QTableWidgetItem *adresHucresi = new QTableWidgetItem();
            QTableWidgetItem *telHucresi = new QTableWidgetItem();
            QTableWidgetItem *mailHucresi = new QTableWidgetItem();
            QTableWidgetItem *subeHucresi = new QTableWidgetItem();
            QTableWidgetItem *gondericiHucresi = new QTableWidgetItem();
            QTableWidgetItem *alinanUrunHucresi = new QTableWidgetItem();

            kodHucresi->setText(bul->getKodStr());
            adHucresi->setText(bul->getAdStr());
            soyadHucresi->setText(bul->getSoyadStr());
            adresHucresi->setText(bul->getAdresStr());
            telHucresi->setText(bul->getTelStr());
            mailHucresi->setText(bul->getMailStr());
            subeHucresi->setText(bul->getAlinanSube());
            gondericiHucresi->setText(bul->getGonderMusteri());
            alinanUrunHucresi->setText(bul->getAlinanUrun());

            ui->tblListele->setItem(0,0,kodHucresi);
            ui->tblListele->setItem(0,1,adHucresi);
            ui->tblListele->setItem(0,2,soyadHucresi);
            ui->tblListele->setItem(0,3,adresHucresi);
            ui->tblListele->setItem(0,4,telHucresi);
            ui->tblListele->setItem(0,5,mailHucresi);
            ui->tblListele->setItem(0,6,subeHucresi);
            ui->tblListele->setItem(0,7,gondericiHucresi);
            ui->tblListele->setItem(0,8,alinanUrunHucresi);

        }
    }

    if (ui->rBtnGondericiUrunAra->isChecked()) {
        QList<urun *> bul = veritabani::getVeritabani()->urunGondericiAra(ui->lnMusteriKodu->text());
        if (bul.count() == 0) {
            QMessageBox::information(this,"Bilgilendirme","Müşteriye Ait Ürün Bilgisi Bulunamadı.");
        }
        else{
            int c = ui->tblListele->columnCount();
            for (int i = 0; i < c; i++) {
                ui->tblListele->removeColumn(0);
            }
            ui->tblListele->setColumnCount(8);
            QStringList sutunlar;
            sutunlar.append("Kod");
            sutunlar.append("Tip");
            sutunlar.append("Ağırlık");
            sutunlar.append("Hacim");
            sutunlar.append("Fiyat");
            sutunlar.append("Alıcı Kod");
            sutunlar.append("Gönderici Kod");
            sutunlar.append("Durum");

            ui->tblListele->setHorizontalHeaderLabels(sutunlar);

            ui->tblListele->setRowCount(bul.count());
            for (int i = 0; i < bul.count(); ++i) {

                QTableWidgetItem *kodHuceresi = new QTableWidgetItem();
                QTableWidgetItem *tipHucresi = new QTableWidgetItem();
                QTableWidgetItem *agirlikHucresi = new QTableWidgetItem();
                QTableWidgetItem *hacimHucresi = new QTableWidgetItem();
                QTableWidgetItem *fiyatHucresi = new QTableWidgetItem();
                QTableWidgetItem *aliciMusteriHucresi = new QTableWidgetItem();
                QTableWidgetItem *gondericiMusteriHucresi = new QTableWidgetItem();
                QTableWidgetItem *durumHucresi = new QTableWidgetItem();

                kodHuceresi->setText(bul[i]->getKodStr());
                tipHucresi->setText(bul[i]->getTipStr());
                agirlikHucresi->setText(QString::number(bul[i]->getAgirliDbl()));
                hacimHucresi->setText(QString::number(bul[i]->getHacimDbl()));
                fiyatHucresi->setText(QString::number(bul[i]->getFiyatDbl()));
                aliciMusteriHucresi->setText(bul[i]->getAliciMusteri());
                gondericiMusteriHucresi->setText(bul[i]->getGondericiMusteri());
                durumHucresi->setText(QString::number(bul[i]->getDurum()));

                ui->tblListele->setItem(i,0,kodHuceresi);
                ui->tblListele->setItem(i,1,tipHucresi);
                ui->tblListele->setItem(i,2,agirlikHucresi);
                ui->tblListele->setItem(i,3,hacimHucresi);
                ui->tblListele->setItem(i,4,fiyatHucresi);
                ui->tblListele->setItem(i,5,aliciMusteriHucresi);
                ui->tblListele->setItem(i,6,gondericiMusteriHucresi);
                ui->tblListele->setItem(i,7,durumHucresi);
            }
        }
    }
}

void gondericiAra::on_btnAdAra_clicked()
{
    if (ui->rBtnGondericiAra->isChecked()) {
        if (ui->lnMusteriAdi->text() != NULL && ui->lnMusteriSoyadi->text() == NULL) {

            QList<gonderici*> bul = veritabani::getVeritabani()->gondericiAdAra(ui->lnMusteriAdi->text());

            if (bul.count() == 0) {
                QMessageBox::information(this,"Bilgilendirme","Aradığınız Ada ait müşteri bilgisi bulunamadı.");
            }
            else{
                int c = ui->tblListele->columnCount();
                for (int i = 0; i < c; i++) {
                    ui->tblListele->removeColumn(0);
                }
                ui->tblListele->setColumnCount(8);
                QStringList sutunlar;
                sutunlar.append("Kod");
                sutunlar.append("Ad");
                sutunlar.append("Soyad");
                sutunlar.append("Adres");
                sutunlar.append("Tel");
                sutunlar.append("Mail");
                sutunlar.append("Şube");
                sutunlar.append("En Son Ürün");

                ui->tblListele->setHorizontalHeaderLabels(sutunlar);

                ui->tblListele->setRowCount(bul.count());
                for (int i = 0; i < bul.count(); ++i) {
                    QTableWidgetItem *kodHucresi = new QTableWidgetItem();
                    QTableWidgetItem *adHucresi = new QTableWidgetItem();
                    QTableWidgetItem *soyadHucresi = new QTableWidgetItem();
                    QTableWidgetItem *adresHucresi = new QTableWidgetItem();
                    QTableWidgetItem *telHucresi = new QTableWidgetItem();
                    QTableWidgetItem *mailHucresi = new QTableWidgetItem();
                    QTableWidgetItem *subeHucresi = new QTableWidgetItem();
                    QTableWidgetItem *gonderilenUrunHucresi = new QTableWidgetItem();


                    kodHucresi->setText(bul[i]->getKodStr());
                    adHucresi->setText(bul[i]->getAdStr());
                    soyadHucresi->setText(bul[i]->getSoyadStr());
                    adresHucresi->setText(bul[i]->getAdresStr());
                    telHucresi->setText(bul[i]->getTelStr());
                    mailHucresi->setText(bul[i]->getMailStr());
                    subeHucresi->setText(bul[i]->getGondericiSube());
                    gonderilenUrunHucresi->setText(bul[i]->getGonderilenUrun());


                    ui->tblListele->setItem(i,0,kodHucresi);
                    ui->tblListele->setItem(i,1,adHucresi);
                    ui->tblListele->setItem(i,2,soyadHucresi);
                    ui->tblListele->setItem(i,3,adresHucresi);
                    ui->tblListele->setItem(i,4,telHucresi);
                    ui->tblListele->setItem(i,5,mailHucresi);
                    ui->tblListele->setItem(i,6,subeHucresi);
                    ui->tblListele->setItem(i,7,gonderilenUrunHucresi);
                }

            }
        }
        if (ui->lnMusteriAdi->text() == NULL && ui->lnMusteriSoyadi->text() != NULL) {

            QList<gonderici*> bul = veritabani::getVeritabani()->gondericiSoyadAra(ui->lnMusteriSoyadi->text());

            if (bul.count() == 0) {
                QMessageBox::information(this,"Bilgilendirme","Aradığınız Ada ait müşteri bilgisi bulunamadı.");
            }
            else{
                int c = ui->tblListele->columnCount();
                for (int i = 0; i < c; i++) {
                    ui->tblListele->removeColumn(0);
                }
                ui->tblListele->setColumnCount(8);
                QStringList sutunlar;
                sutunlar.append("Kod");
                sutunlar.append("Ad");
                sutunlar.append("Soyad");
                sutunlar.append("Adres");
                sutunlar.append("Tel");
                sutunlar.append("Mail");
                sutunlar.append("Şube");
                sutunlar.append("En Son Ürün");

                ui->tblListele->setHorizontalHeaderLabels(sutunlar);

                ui->tblListele->setRowCount(bul.count());
                for (int i = 0; i < bul.count(); ++i) {
                    QTableWidgetItem *kodHucresi = new QTableWidgetItem();
                    QTableWidgetItem *adHucresi = new QTableWidgetItem();
                    QTableWidgetItem *soyadHucresi = new QTableWidgetItem();
                    QTableWidgetItem *adresHucresi = new QTableWidgetItem();
                    QTableWidgetItem *telHucresi = new QTableWidgetItem();
                    QTableWidgetItem *mailHucresi = new QTableWidgetItem();
                    QTableWidgetItem *subeHucresi = new QTableWidgetItem();
                    QTableWidgetItem *gonderilenUrunHucresi = new QTableWidgetItem();


                    kodHucresi->setText(bul[i]->getKodStr());
                    adHucresi->setText(bul[i]->getAdStr());
                    soyadHucresi->setText(bul[i]->getSoyadStr());
                    adresHucresi->setText(bul[i]->getAdresStr());
                    telHucresi->setText(bul[i]->getTelStr());
                    mailHucresi->setText(bul[i]->getMailStr());
                    subeHucresi->setText(bul[i]->getGondericiSube());
                    gonderilenUrunHucresi->setText(bul[i]->getGonderilenUrun());


                    ui->tblListele->setItem(i,0,kodHucresi);
                    ui->tblListele->setItem(i,1,adHucresi);
                    ui->tblListele->setItem(i,2,soyadHucresi);
                    ui->tblListele->setItem(i,3,adresHucresi);
                    ui->tblListele->setItem(i,4,telHucresi);
                    ui->tblListele->setItem(i,5,mailHucresi);
                    ui->tblListele->setItem(i,6,subeHucresi);
                    ui->tblListele->setItem(i,7,gonderilenUrunHucresi);
                }

            }
        }
        if (ui->lnMusteriAdi->text() != NULL && ui->lnMusteriSoyadi->text() != NULL) {
            QList<gonderici*> bul = veritabani::getVeritabani()->gondericiAdSoyadAra(ui->lnMusteriAdi->text(),ui->lnMusteriSoyadi->text());

            if (bul.count() == 0) {
                QMessageBox::information(this,"Bilgilendirme","Aradığınız Ada ait müşteri bilgisi bulunamadı.");
            }
            else{
                int c = ui->tblListele->columnCount();
                for (int i = 0; i < c; i++) {
                    ui->tblListele->removeColumn(0);
                }
                ui->tblListele->setColumnCount(8);
                QStringList sutunlar;
                sutunlar.append("Kod");
                sutunlar.append("Ad");
                sutunlar.append("Soyad");
                sutunlar.append("Adres");
                sutunlar.append("Tel");
                sutunlar.append("Mail");
                sutunlar.append("Şube");
                sutunlar.append("En Son Ürün");

                ui->tblListele->setHorizontalHeaderLabels(sutunlar);

                ui->tblListele->setRowCount(bul.count());
                for (int i = 0; i < bul.count(); ++i) {
                    QTableWidgetItem *kodHucresi = new QTableWidgetItem();
                    QTableWidgetItem *adHucresi = new QTableWidgetItem();
                    QTableWidgetItem *soyadHucresi = new QTableWidgetItem();
                    QTableWidgetItem *adresHucresi = new QTableWidgetItem();
                    QTableWidgetItem *telHucresi = new QTableWidgetItem();
                    QTableWidgetItem *mailHucresi = new QTableWidgetItem();
                    QTableWidgetItem *subeHucresi = new QTableWidgetItem();
                    QTableWidgetItem *gonderilenUrunHucresi = new QTableWidgetItem();


                    kodHucresi->setText(bul[i]->getKodStr());
                    adHucresi->setText(bul[i]->getAdStr());
                    soyadHucresi->setText(bul[i]->getSoyadStr());
                    adresHucresi->setText(bul[i]->getAdresStr());
                    telHucresi->setText(bul[i]->getTelStr());
                    mailHucresi->setText(bul[i]->getMailStr());
                    subeHucresi->setText(bul[i]->getGondericiSube());
                    gonderilenUrunHucresi->setText(bul[i]->getGonderilenUrun());


                    ui->tblListele->setItem(i,0,kodHucresi);
                    ui->tblListele->setItem(i,1,adHucresi);
                    ui->tblListele->setItem(i,2,soyadHucresi);
                    ui->tblListele->setItem(i,3,adresHucresi);
                    ui->tblListele->setItem(i,4,telHucresi);
                    ui->tblListele->setItem(i,5,mailHucresi);
                    ui->tblListele->setItem(i,6,subeHucresi);
                    ui->tblListele->setItem(i,7,gonderilenUrunHucresi);
                }

            }
        }
    }
    if (ui->rBtnAliciAra->isChecked()) {
        if (ui->lnMusteriAdi->text() != NULL && ui->lnMusteriSoyadi->text() == NULL) {
            QList<alici *> bul = veritabani::getVeritabani()->aliciAdAra(ui->lnMusteriAdi->text());

            if (bul.count() == 0) {

                QMessageBox::information(this,"Bilgilendirme","Aradığınız koda ait müşteri bilgisi bulunamadı.");
            }
            else{
                ui->tblListele->setColumnCount(9);
                QStringList sutunlar;
                sutunlar.append("Kod");
                sutunlar.append("Ad");
                sutunlar.append("Soyad");
                sutunlar.append("Adres");
                sutunlar.append("Tel");
                sutunlar.append("Mail");
                sutunlar.append("Şube");
                sutunlar.append("Alınan Ürün");
                sutunlar.append("Gönderici Kodu");


                ui->tblListele->setHorizontalHeaderLabels(sutunlar);
                ui->tblListele->setRowCount(bul.count());
                for (int i = 0; i < bul.count(); ++i) {
                    QTableWidgetItem *kodHucresi = new QTableWidgetItem();
                    QTableWidgetItem *adHucresi = new QTableWidgetItem();
                    QTableWidgetItem *soyadHucresi = new QTableWidgetItem();
                    QTableWidgetItem *adresHucresi = new QTableWidgetItem();
                    QTableWidgetItem *telHucresi = new QTableWidgetItem();
                    QTableWidgetItem *mailHucresi = new QTableWidgetItem();
                    QTableWidgetItem *subeHucresi = new QTableWidgetItem();
                    QTableWidgetItem *gondericiHucresi = new QTableWidgetItem();
                    QTableWidgetItem *alinanUrunHucresi = new QTableWidgetItem();

                    kodHucresi->setText(bul[i]->getKodStr());
                    adHucresi->setText(bul[i]->getAdStr());
                    soyadHucresi->setText(bul[i]->getSoyadStr());
                    adresHucresi->setText(bul[i]->getAdresStr());
                    telHucresi->setText(bul[i]->getTelStr());
                    mailHucresi->setText(bul[i]->getMailStr());
                    subeHucresi->setText(bul[i]->getAlinanSube());
                    gondericiHucresi->setText(bul[i]->getGonderMusteri());
                    alinanUrunHucresi->setText(bul[i]->getAlinanUrun());

                    ui->tblListele->setItem(i,0,kodHucresi);
                    ui->tblListele->setItem(i,1,adHucresi);
                    ui->tblListele->setItem(i,2,soyadHucresi);
                    ui->tblListele->setItem(i,3,adresHucresi);
                    ui->tblListele->setItem(i,4,telHucresi);
                    ui->tblListele->setItem(i,5,mailHucresi);
                    ui->tblListele->setItem(i,6,subeHucresi);
                    ui->tblListele->setItem(i,7,gondericiHucresi);
                    ui->tblListele->setItem(i,8,alinanUrunHucresi);

                }
            }
        }
        if (ui->lnMusteriAdi->text() == NULL && ui->lnMusteriSoyadi->text() != NULL) {

            QList<alici *> bul = veritabani::getVeritabani()->aliciSoyadAra(ui->lnMusteriSoyadi->text());

            if (bul.count() == 0) {
                QMessageBox::information(this,"Bilgilendirme","Aradığınız koda ait müşteri bilgisi bulunamadı.");
            }
            else{
                ui->tblListele->setColumnCount(9);
                QStringList sutunlar;
                sutunlar.append("Kod");
                sutunlar.append("Ad");
                sutunlar.append("Soyad");
                sutunlar.append("Adres");
                sutunlar.append("Tel");
                sutunlar.append("Mail");
                sutunlar.append("Şube");
                sutunlar.append("Alınan Ürün");
                sutunlar.append("Gönderici Kodu");


                ui->tblListele->setHorizontalHeaderLabels(sutunlar);
                ui->tblListele->setRowCount(bul.count());
                for (int i = 0; i < bul.count(); ++i) {
                    QTableWidgetItem *kodHucresi = new QTableWidgetItem();
                    QTableWidgetItem *adHucresi = new QTableWidgetItem();
                    QTableWidgetItem *soyadHucresi = new QTableWidgetItem();
                    QTableWidgetItem *adresHucresi = new QTableWidgetItem();
                    QTableWidgetItem *telHucresi = new QTableWidgetItem();
                    QTableWidgetItem *mailHucresi = new QTableWidgetItem();
                    QTableWidgetItem *subeHucresi = new QTableWidgetItem();
                    QTableWidgetItem *gondericiHucresi = new QTableWidgetItem();
                    QTableWidgetItem *alinanUrunHucresi = new QTableWidgetItem();

                    kodHucresi->setText(bul[i]->getKodStr());
                    adHucresi->setText(bul[i]->getAdStr());
                    soyadHucresi->setText(bul[i]->getSoyadStr());
                    adresHucresi->setText(bul[i]->getAdresStr());
                    telHucresi->setText(bul[i]->getTelStr());
                    mailHucresi->setText(bul[i]->getMailStr());
                    subeHucresi->setText(bul[i]->getAlinanSube());
                    gondericiHucresi->setText(bul[i]->getGonderMusteri());
                    alinanUrunHucresi->setText(bul[i]->getAlinanUrun());

                    ui->tblListele->setItem(i,0,kodHucresi);
                    ui->tblListele->setItem(i,1,adHucresi);
                    ui->tblListele->setItem(i,2,soyadHucresi);
                    ui->tblListele->setItem(i,3,adresHucresi);
                    ui->tblListele->setItem(i,4,telHucresi);
                    ui->tblListele->setItem(i,5,mailHucresi);
                    ui->tblListele->setItem(i,6,subeHucresi);
                    ui->tblListele->setItem(i,7,gondericiHucresi);
                    ui->tblListele->setItem(i,8,alinanUrunHucresi);
                }

            }
        }
        if (ui->lnMusteriAdi->text() != NULL && ui->lnMusteriSoyadi->text() != NULL) {

            QList<alici *> bul = veritabani::getVeritabani()->aliciAdSoyadSoyadAra(ui->lnMusteriAdi->text(),ui->lnMusteriSoyadi->text());

            if (bul.count() == 0) {
                QMessageBox::information(this,"Bilgilendirme","Aradığınız koda ait müşteri bilgisi bulunamadı.");
            }
            else{
                ui->tblListele->setColumnCount(9);
                QStringList sutunlar;
                sutunlar.append("Kod");
                sutunlar.append("Ad");
                sutunlar.append("Soyad");
                sutunlar.append("Adres");
                sutunlar.append("Tel");
                sutunlar.append("Mail");
                sutunlar.append("Şube");
                sutunlar.append("Alınan Ürün");
                sutunlar.append("Gönderici Kodu");


                ui->tblListele->setHorizontalHeaderLabels(sutunlar);
                ui->tblListele->setRowCount(bul.count());
                for (int i = 0; i < bul.count(); ++i) {
                    QTableWidgetItem *kodHucresi = new QTableWidgetItem();
                    QTableWidgetItem *adHucresi = new QTableWidgetItem();
                    QTableWidgetItem *soyadHucresi = new QTableWidgetItem();
                    QTableWidgetItem *adresHucresi = new QTableWidgetItem();
                    QTableWidgetItem *telHucresi = new QTableWidgetItem();
                    QTableWidgetItem *mailHucresi = new QTableWidgetItem();
                    QTableWidgetItem *subeHucresi = new QTableWidgetItem();
                    QTableWidgetItem *gondericiHucresi = new QTableWidgetItem();
                    QTableWidgetItem *alinanUrunHucresi = new QTableWidgetItem();

                    kodHucresi->setText(bul[i]->getKodStr());
                    adHucresi->setText(bul[i]->getAdStr());
                    soyadHucresi->setText(bul[i]->getSoyadStr());
                    adresHucresi->setText(bul[i]->getAdresStr());
                    telHucresi->setText(bul[i]->getTelStr());
                    mailHucresi->setText(bul[i]->getMailStr());
                    subeHucresi->setText(bul[i]->getAlinanSube());
                    gondericiHucresi->setText(bul[i]->getGonderMusteri());
                    alinanUrunHucresi->setText(bul[i]->getAlinanUrun());

                    ui->tblListele->setItem(i,0,kodHucresi);
                    ui->tblListele->setItem(i,1,adHucresi);
                    ui->tblListele->setItem(i,2,soyadHucresi);
                    ui->tblListele->setItem(i,3,adresHucresi);
                    ui->tblListele->setItem(i,4,telHucresi);
                    ui->tblListele->setItem(i,5,mailHucresi);
                    ui->tblListele->setItem(i,6,subeHucresi);
                    ui->tblListele->setItem(i,7,gondericiHucresi);
                    ui->tblListele->setItem(i,8,alinanUrunHucresi);
                }
            }
        }
    }
    if (ui->rBtnGondericiUrunAra->isChecked()) {

        QMessageBox::information(this,"Bilgilendirme","Ürünü gönderici koduna göre aratınız...");
    }
}

void gondericiAra::on_btnTumu_clicked()
{
    if (ui->rBtnGondericiUrunAra->isChecked()) {
        QList<urun*> bul = veritabani::getVeritabani()->urunTumuAra();
        int c = ui->tblListele->columnCount();
        for (int i = 0; i < c; i++) {
            ui->tblListele->removeColumn(0);
        }
        ui->tblListele->setColumnCount(8);
        QStringList sutunlar;
        sutunlar.append("Kod");
        sutunlar.append("Tip");
        sutunlar.append("Ağırlık");
        sutunlar.append("Hacim");
        sutunlar.append("Fiyat");
        sutunlar.append("Alıcı Kod");
        sutunlar.append("Gönderici Kod");
        sutunlar.append("Durum");

        ui->tblListele->setHorizontalHeaderLabels(sutunlar);
        ui->tblListele->setRowCount(bul.count());


        for (int i = 0; i < bul.count(); ++i) {
            QTableWidgetItem *kodHuceresi = new QTableWidgetItem();
            QTableWidgetItem *tipHucresi = new QTableWidgetItem();
            QTableWidgetItem *agirlikHucresi = new QTableWidgetItem();
            QTableWidgetItem *hacimHucresi = new QTableWidgetItem();
            QTableWidgetItem *fiyatHucresi = new QTableWidgetItem();
            QTableWidgetItem *aliciMusteriHucresi = new QTableWidgetItem();
            QTableWidgetItem *gondericiMusteriHucresi = new QTableWidgetItem();
            QTableWidgetItem *durumHucresi = new QTableWidgetItem();

            kodHuceresi->setText(bul[i]->getKodStr());
            tipHucresi->setText(bul[i]->getTipStr());
            agirlikHucresi->setText(QString::number(bul[i]->getAgirliDbl()));
            hacimHucresi->setText(QString::number(bul[i]->getHacimDbl()));
            fiyatHucresi->setText(QString::number(bul[i]->getFiyatDbl()));
            aliciMusteriHucresi->setText(bul[i]->getAliciMusteri());
            gondericiMusteriHucresi->setText(bul[i]->getGondericiMusteri());
            durumHucresi->setText(QString::number(bul[i]->getDurum()));

            ui->tblListele->setItem(i,0,kodHuceresi);
            ui->tblListele->setItem(i,1,tipHucresi);
            ui->tblListele->setItem(i,2,agirlikHucresi);
            ui->tblListele->setItem(i,3,hacimHucresi);
            ui->tblListele->setItem(i,4,fiyatHucresi);
            ui->tblListele->setItem(i,5,aliciMusteriHucresi);
            ui->tblListele->setItem(i,6,gondericiMusteriHucresi);
            ui->tblListele->setItem(i,7,durumHucresi);
        }
    }
    if (ui->rBtnGondericiAra->isChecked()) {
        QList<gonderici *> bul = veritabani::getVeritabani()->gondericiTumuAra();

        if (bul.count()==0) {
            QMessageBox::information(this,"Bilgilendirme","Müşteri bilgisine ulaşılamadı.");
        }else{
            int c = ui->tblListele->columnCount();
            for (int i = 0; i < c; i++) { //Sütunlar ürün için hazırlanması
                ui->tblListele->removeColumn(0);
            }
            ui->tblListele->setColumnCount(8);
            QStringList sutunlar;
            sutunlar.append("Kod");
            sutunlar.append("Ad");
            sutunlar.append("Soyad");
            sutunlar.append("Adres");
            sutunlar.append("Tel");
            sutunlar.append("Mail");
            sutunlar.append("Şube");
            sutunlar.append("En Son Ürün");

            ui->tblListele->setHorizontalHeaderLabels(sutunlar);
            ui->tblListele->setRowCount(bul.count());
            for (int i = 0; i < bul.count(); ++i) {
                QTableWidgetItem *kodHucresi = new QTableWidgetItem();
                QTableWidgetItem *adHucresi = new QTableWidgetItem();
                QTableWidgetItem *soyadHucresi = new QTableWidgetItem();
                QTableWidgetItem *adresHucresi = new QTableWidgetItem();
                QTableWidgetItem *telHucresi = new QTableWidgetItem();
                QTableWidgetItem *mailHucresi = new QTableWidgetItem();
                QTableWidgetItem *subeHucresi = new QTableWidgetItem();
                QTableWidgetItem *gonderilenUrunHucresi = new QTableWidgetItem();

                kodHucresi->setText(bul[i]->getKodStr());
                adHucresi->setText(bul[i]->getAdStr());
                soyadHucresi->setText(bul[i]->getSoyadStr());
                adresHucresi->setText(bul[i]->getAdresStr());
                telHucresi->setText(bul[i]->getTelStr());
                mailHucresi->setText(bul[i]->getMailStr());
                subeHucresi->setText(bul[i]->getGondericiSube());
                gonderilenUrunHucresi->setText(bul[i]->getGonderilenUrun());

                ui->tblListele->setItem(i,0,kodHucresi);
                ui->tblListele->setItem(i,1,adHucresi);
                ui->tblListele->setItem(i,2,soyadHucresi);
                ui->tblListele->setItem(i,3,adresHucresi);
                ui->tblListele->setItem(i,4,telHucresi);
                ui->tblListele->setItem(i,5,mailHucresi);
                ui->tblListele->setItem(i,6,subeHucresi);
                ui->tblListele->setItem(i,7,gonderilenUrunHucresi);
            }
        }
    }
    if (ui->rBtnAliciAra->isChecked()) {
        QList<alici *> bul = veritabani::getVeritabani()->aliciTumuAra();

        if (bul.count() == 0) {
            QMessageBox::information(this,"Bilgilendirme","Aradığınız koda ait müşteri bilgisi bulunamadı.");
        }
        else{
            int c = ui->tblListele->columnCount();
            for (int i = 0; i < c; i++) { //Sütunlar ürün için hazırlanması
                ui->tblListele->removeColumn(0);
            }
            ui->tblListele->setColumnCount(9);
            QStringList sutunlar;
            sutunlar.append("Kod");
            sutunlar.append("Ad");
            sutunlar.append("Soyad");
            sutunlar.append("Adres");
            sutunlar.append("Tel");
            sutunlar.append("Mail");
            sutunlar.append("Alınan Şube");
            sutunlar.append("Alınan Ürün");
            sutunlar.append("Gönderici Kodu");

            ui->tblListele->setHorizontalHeaderLabels(sutunlar);
            ui->tblListele->setRowCount(bul.count());
            for (int i = 0; i < bul.count(); ++i) {
                QTableWidgetItem *kodHucresi = new QTableWidgetItem();
                QTableWidgetItem *adHucresi = new QTableWidgetItem();
                QTableWidgetItem *soyadHucresi = new QTableWidgetItem();
                QTableWidgetItem *adresHucresi = new QTableWidgetItem();
                QTableWidgetItem *telHucresi = new QTableWidgetItem();
                QTableWidgetItem *mailHucresi = new QTableWidgetItem();
                QTableWidgetItem *alinanUrunHucresi = new QTableWidgetItem();
                QTableWidgetItem *gondericiHucresi = new QTableWidgetItem();
                QTableWidgetItem *subeHucresi = new QTableWidgetItem();


                kodHucresi->setText(bul[i]->getKodStr());
                adHucresi->setText(bul[i]->getAdStr());
                soyadHucresi->setText(bul[i]->getSoyadStr());
                adresHucresi->setText(bul[i]->getAdresStr());
                telHucresi->setText(bul[i]->getTelStr());
                mailHucresi->setText(bul[i]->getMailStr());
                alinanUrunHucresi->setText(bul[i]->getAlinanUrun());
                gondericiHucresi->setText(bul[i]->getGonderMusteri());
                subeHucresi->setText(bul[i]->getAlinanSube());

                ui->tblListele->setItem(i,0,kodHucresi);
                ui->tblListele->setItem(i,1,adHucresi);
                ui->tblListele->setItem(i,2,soyadHucresi);
                ui->tblListele->setItem(i,3,adresHucresi);
                ui->tblListele->setItem(i,4,telHucresi);
                ui->tblListele->setItem(i,5,mailHucresi);
                ui->tblListele->setItem(i,6,alinanUrunHucresi);
                ui->tblListele->setItem(i,7,gondericiHucresi);
                ui->tblListele->setItem(i,8,subeHucresi);
            }
        }
    }
}

void gondericiAra::on_btnKargoHazirla_clicked()
{
    if (ui->rBtnGondericiAra->isChecked()) {
        if (ui->tblListele->currentRow() == -1) {
            QMessageBox::information(this,"Bilgilendirme","Müşteri Seçiniz");
        }else{
            int seciliSatir = ui->tblListele->currentRow();
            gonderici *ekle = new gonderici();
            ekle->setKodStr(ui->tblListele->item(seciliSatir,0)->text());
            ekle->setAdStr(ui->tblListele->item(seciliSatir,1)->text());
            ekle->setSoyadStr(ui->tblListele->item(seciliSatir,2)->text());
            ekle->setAdresStr(ui->tblListele->item(seciliSatir,3)->text());
            ekle->setTelStr(ui->tblListele->item(seciliSatir,4)->text());
            ekle->setMailStr(ui->tblListele->item(seciliSatir,5)->text());
            ekle->setGondericiSube(ui->tblListele->item(seciliSatir,6)->text());
            ekle->setGonderilenUrun(ui->tblListele->item(seciliSatir,7)->text());
            QMessageBox::information(this,"Bilgilendirme","Kargo Hazırla....");
            close();
            kargoTeslim* git=new kargoTeslim(ekle,NULL);
            git->show();
        }

    }
    if (ui->rBtnAliciAra->isChecked()) {
        if (ui->tblListele->currentRow() == -1) {
            QMessageBox::information(this,"Bilgilendirme","Müşteri Seçiniz");
        }else{
            int seciliSatir = ui->tblListele->currentRow();
            alici *ekle = new alici();
            ekle->setKodStr(ui->tblListele->item(seciliSatir,0)->text());
            ekle->setAdStr(ui->tblListele->item(seciliSatir,1)->text());
            ekle->setSoyadStr(ui->tblListele->item(seciliSatir,2)->text());
            ekle->setSoyadStr(ui->tblListele->item(seciliSatir,3)->text());
            ekle->setAdresStr(ui->tblListele->item(seciliSatir,4)->text());
            ekle->setTelStr(ui->tblListele->item(seciliSatir,5)->text());
            ekle->setMailStr(ui->tblListele->item(seciliSatir,0)->text());
            ekle->setGonderMusteri(ui->tblListele->item(seciliSatir,0)->text());
            ekle->setAlinanSube(ui->tblListele->item(seciliSatir,0)->text());

            QMessageBox::information(this,"Bilgilendirme","Kargo Hazırla....");
            close();
            kargoTeslim* git=new kargoTeslim(NULL,ekle);
            git->show();
        }
    }
    if (ui->rBtnGondericiUrunAra->isChecked()) {
        if (ui->tblListele->currentRow() == -1) {

            QMessageBox::information(this,"Bilgilendirme","Ürün Seçiniz");
        }else{
            int secilisatir = ui->tblListele->currentRow();
            urun *ekle = new urun();
            ekle->setKodStr(ui->tblListele->item(secilisatir,0)->text());

            close();
            guzergahOlustur  *git = new guzergahOlustur(ekle);
            git->show();


        }
    }
}

void gondericiAra::on_btnEkle_clicked()
{
    QMessageBox::information(this,"Bilgilendirme","Gönderici ekleme sayfasına yönlendiriliyorsunuz.");
    close();
    gondericiEkle* git=new gondericiEkle;
    git->show();
}

void gondericiAra::on_btnSil_clicked()
{
    if (ui->tblListele->currentRow() == -1 ) {

        QMessageBox::information(this,"Bilgilendirme","Satır Seçmediniz");
    }
    else{
        if (ui->rBtnGondericiAra->isChecked()) {
            int seciliSatir = ui->tblListele->currentRow();
            gonderici *silinecek = new gonderici();
            silinecek->setKodStr(ui->tblListele->item(seciliSatir,0)->text());
            silinecek->setAdStr(ui->tblListele->item(seciliSatir,1)->text());
            silinecek->setSoyadStr(ui->tblListele->item(seciliSatir,2)->text());
            silinecek->setAdresStr(ui->tblListele->item(seciliSatir,3)->text());
            silinecek->setTelStr(ui->tblListele->item(seciliSatir,4)->text());
            silinecek->setMailStr(ui->tblListele->item(seciliSatir,5)->text());
            silinecek->setGondericiSube(ui->tblListele->item(seciliSatir,6)->text());
            silinecek->setGonderilenUrun(ui->tblListele->item(seciliSatir,7)->text());

            veritabani::getVeritabani()->gondericiSil(silinecek);
            ui->tblListele->removeRow(ui->tblListele->currentRow());
        }
        if (ui->rBtnAliciAra->isChecked()) {
            int seciliSatir = ui->tblListele->currentRow();
            alici *sil = new alici();
            sil->setKodStr(ui->tblListele->item(seciliSatir,0)->text());
            sil->setAdStr(ui->tblListele->item(seciliSatir,1)->text());
            sil->setSoyadStr(ui->tblListele->item(seciliSatir,2)->text());
            sil->setSoyadStr(ui->tblListele->item(seciliSatir,3)->text());
            sil->setAdresStr(ui->tblListele->item(seciliSatir,4)->text());
            sil->setTelStr(ui->tblListele->item(seciliSatir,5)->text());
            sil->setMailStr(ui->tblListele->item(seciliSatir,0)->text());
            sil->setGonderMusteri(ui->tblListele->item(seciliSatir,0)->text());
            sil->setAlinanSube(ui->tblListele->item(seciliSatir,0)->text());

            veritabani::getVeritabani()->aliciSil(sil);
            ui->tblListele->removeRow(ui->tblListele->currentRow());
        }
        if (ui->rBtnGondericiUrunAra->isChecked()) {
            int seciliSatir = ui->tblListele->currentRow();
            urun *sil = new urun();
            sil->setKodStr(ui->tblListele->item(seciliSatir,0)->text());
            sil->setTipStr(ui->tblListele->item(seciliSatir,1)->text());
            sil->setAgirliDbl(ui->tblListele->item(seciliSatir,2)->text().toDouble());
            sil->setHacimDbl(ui->tblListele->item(seciliSatir,3)->text().toDouble());
            sil->setFiyatDbl(ui->tblListele->item(seciliSatir,4)->text().toDouble());
            sil->setAliciMusteri(ui->tblListele->item(seciliSatir,5)->text());
            sil->setGondericiMusteri(ui->tblListele->item(seciliSatir,6)->text());
            sil->setDurum(ui->tblListele->item(seciliSatir,7)->text().toInt());

            veritabani::getVeritabani()->urunSil(sil);
            ui->tblListele->removeRow(ui->tblListele->currentRow());
        }
    }
}

void gondericiAra::on_btnGuncelle_clicked()
{
    if (ui->tblListele->currentRow()) {

        QMessageBox::information(this,"Bilgilendirme","Satır Seçiniz...");
    }else{
        if (ui->rBtnGondericiAra->isChecked()) {
            int seciliSatir = ui->tblListele->currentRow();
            gonderici *guncellenecek = new gonderici();
            guncellenecek->setKodStr(ui->tblListele->item(seciliSatir,0)->text());
            guncellenecek->setAdStr(ui->tblListele->item(seciliSatir,1)->text());
            guncellenecek->setSoyadStr(ui->tblListele->item(seciliSatir,2)->text());
            guncellenecek->setAdresStr(ui->tblListele->item(seciliSatir,3)->text());
            guncellenecek->setTelStr(ui->tblListele->item(seciliSatir,4)->text());
            guncellenecek->setMailStr(ui->tblListele->item(seciliSatir,5)->text());
            guncellenecek->setGondericiSube(ui->tblListele->item(seciliSatir,6)->text());
            guncellenecek->setGonderilenUrun(ui->tblListele->item(seciliSatir,7)->text());

            veritabani::getVeritabani()->gondericiGuncelle(guncellenecek);
        }
        if (ui->rBtnAliciAra->isChecked()) {
            int seciliSatir = ui->tblListele->currentRow();
            alici *guncelle = new alici();
            guncelle->setKodStr(ui->tblListele->item(seciliSatir,0)->text());
            guncelle->setAdStr(ui->tblListele->item(seciliSatir,1)->text());
            guncelle->setSoyadStr(ui->tblListele->item(seciliSatir,2)->text());

            guncelle->setAdresStr(ui->tblListele->item(seciliSatir,3)->text());
            guncelle->setTelStr(ui->tblListele->item(seciliSatir,4)->text());
            guncelle->setMailStr(ui->tblListele->item(seciliSatir,5)->text());
            guncelle->setAlinanUrun(ui->tblListele->item(seciliSatir,6)->text());
            guncelle->setGonderMusteri(ui->tblListele->item(seciliSatir,0)->text());
            guncelle->setAlinanSube(ui->tblListele->item(seciliSatir,0)->text());

            veritabani::getVeritabani()->aliciGuncelle(guncelle);
        }
        if(ui->rBtnGondericiUrunAra->isChecked()){
            int seciliSatir = ui->tblListele->currentRow();
            urun *guncelle = new urun();
            guncelle->setKodStr(ui->tblListele->item(seciliSatir,0)->text());
            guncelle->setTipStr(ui->tblListele->item(seciliSatir,1)->text());
            guncelle->setAgirliDbl(ui->tblListele->item(seciliSatir,2)->text().toDouble());
            guncelle->setHacimDbl(ui->tblListele->item(seciliSatir,3)->text().toDouble());
            guncelle->setFiyatDbl(ui->tblListele->item(seciliSatir,4)->text().toDouble());
            guncelle->setAliciMusteri(ui->tblListele->item(seciliSatir,5)->text());
            guncelle->setGondericiMusteri(ui->tblListele->item(seciliSatir,6)->text());
            guncelle->setDurum(ui->tblListele->item(seciliSatir,7)->text().toInt());

            veritabani::getVeritabani()->urunGuncelle(guncelle);

        }
    }
}
