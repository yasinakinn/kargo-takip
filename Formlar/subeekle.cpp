#include "subeekle.h"
#include "ui_subeekle.h"
#include "kargotakip.h"
#include "merkezsubeekle.h"
#include "sehir.h"
#include "sube.h"
#include "veritabani.h"
#include <QtGui>
#include <QMessageBox>


subeEkle::subeEkle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::subeEkle)
{
    ui->setupUi(this);
    QPalette* palette = new QPalette();
    palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap(":/background/background.png")))));
    setPalette(*palette);

    QList<sehir *> sehirGelen = veritabani::getVeritabani()->sehirTumuAra();
    if (sehirGelen.count() != 0) {
        for (int i = 0; i < sehirGelen.count(); ++i) {
            ui->cmbSehir->addItem(sehirGelen[i]->getAdiStr());
        }
    }
}

subeEkle::~subeEkle()
{
    delete ui;
}

void subeEkle::on_btnGeri_clicked()
{
    close();
    KargoTakip* s = new KargoTakip();
    s->show();
}

void subeEkle::on_btnMerkezSube_clicked()
{
    close();
    merkezSubeEkle* s = new merkezSubeEkle();
    s->show();
}

void subeEkle::on_btn_sehirEkle_clicked()
{
    sehir *ekle = new sehir;
    ekle->setKodStr(ui->lnSehirPlakaKod->text());
    ekle->setAdiStr(ui->lnSehirAdi->text());
    ekle->setXKoordinatDbl(ui->ln_xKord->text().toDouble());
    ekle->setYKoordinatDbl(ui->ln_yKord->text().toDouble());

    veritabani::getVeritabani()->sehirEkle(ekle);

    if (ui->lnSehirPlakaKod->text().isEmpty()) {
      QMessageBox::warning(this, tr("Şehir Ekle"),
                           tr("Plaka Kodu Boş Geçilemez!"), QMessageBox::Ok);
      return;
    }
    if (ui->lnSehirAdi->text().isEmpty()) {
      QMessageBox::warning(this, tr("Şehir Ekle"),
                           tr("Şehir Adı Boş Geçilemez!"), QMessageBox::Ok);
      return;
    }
    if (ui->ln_xKord->text().isEmpty()) {
      QMessageBox::warning(this, tr("Şehir Ekle"), tr("x Koordinant Boş Geçilemez!"),
                           QMessageBox::Ok);
      return;
    }
    if (ui->ln_yKord->text().isEmpty()) {
      QMessageBox::warning(this, tr("Şehir Ekle"),
                           tr("y Koordinant Boş Geçilemez!"), QMessageBox::Ok);
      return;
    }

    QMessageBox::information(this, tr("Sehir Ekle"), tr("Şehir Eklendi"),
                             QMessageBox::Ok);
    close();
    subeEkle *s = new subeEkle();
    s->show();
}

void subeEkle::on_btnSubeEkle_clicked()
{
    sube *ekle = new sube;
    if (veritabani::getVeritabani()->subeTumuAra().count() == 0) {

        ekle->setKodStr("500000");
        ekle->setAdiStr(ui->lnAd->text());
        ekle->setTelStr(ui->lnTel->text());
        ekle->setMailStr(ui->lnMail->text());
        ekle->setSubeSehir(veritabani::getVeritabani()->sehirAra(ui->cmbSehir->currentText())->getKodStr());

    }
    else {

        ekle->setKodStr(QString::number(veritabani::getVeritabani()->subeTumuAra().last()->getKodStr().toInt() + 1));
        ekle->setAdiStr(ui->lnAd->text());
        ekle->setTelStr(ui->lnTel->text());
        ekle->setMailStr(ui->lnMail->text());
        ekle->setSubeSehir(veritabani::getVeritabani()->sehirAra(ui->cmbSehir->currentText())->getKodStr());

    }

    veritabani::getVeritabani()->subeEkle(ekle);

    QMessageBox::information(this, tr("Şube Ekle"), tr("Şube Eklendi"),
                             QMessageBox::Ok);

}

void subeEkle::on_btnSehirTumu_clicked()
{
    QList<sehir *> ara = veritabani::getVeritabani()->sehirTumuAra();
    ui->tblSehirListe->setRowCount(ara.count());

    if (ara.count() != 0) {
        for (int i = 0; i < ara.count(); ++i) {
            QTableWidgetItem *kod = new QTableWidgetItem();
            QTableWidgetItem *ad = new QTableWidgetItem();
            QTableWidgetItem *xKord = new QTableWidgetItem();
            QTableWidgetItem *yKord = new QTableWidgetItem();

            kod->setText(ara[i]->getKodStr());
            ad->setText(ara[i]->getAdiStr());
            xKord->setText(QString::number(ara[i]->getXKoordinatDbl()));
            yKord->setText(QString::number(ara[i]->getYKoordinatDbl()));

            ui->tblSehirListe->setItem(i,0,kod);
            ui->tblSehirListe->setItem(i,1,ad);
            ui->tblSehirListe->setItem(i,2,xKord);
            ui->tblSehirListe->setItem(i,3,yKord);
        }
    }
}

void subeEkle::on_btnSubeTumu_clicked()
{
    QList<sube *>ara = veritabani::getVeritabani()->subeTumuAra();
    ui->tblSubeListe->setRowCount(ara.count());

    if (ara.count() != 0) {
        for (int i = 0; i < ara.count(); ++i) {
            QTableWidgetItem *kod = new QTableWidgetItem();
            QTableWidgetItem *ad = new QTableWidgetItem();
            QTableWidgetItem *tel = new QTableWidgetItem();
            QTableWidgetItem *mail = new QTableWidgetItem();
            QTableWidgetItem *sube = new QTableWidgetItem();

            kod->setText(ara[i]->getKodStr());
            ad->setText(ara[i]->getAdiStr());
            tel->setText(ara[i]->getTelStr());
            mail->setText(ara[i]->getMailStr());
            sube->setText(ara[i]->getSubeSehir());

            ui->tblSubeListe->setItem(i,0,kod);
            ui->tblSubeListe->setItem(i,1,ad);
            ui->tblSubeListe->setItem(i,2,tel);
            ui->tblSubeListe->setItem(i,3,mail);
            ui->tblSubeListe->setItem(i,4,sube);
        }

    }
}

void subeEkle::on_btnSehirSil_clicked()
{
    if (ui->tblSehirListe->currentRow() == -1) {

        QMessageBox::information(this,"Bilgilendirme","Satır Seçiniz...");
    }else{
        int seciliSatir = ui->tblSehirListe->currentRow();
        sehir *silinecek = new sehir(this);
        silinecek->setKodStr(ui->tblSehirListe->item(seciliSatir,0)->text());
        silinecek->setAdiStr(ui->tblSehirListe->item(seciliSatir,1)->text());
        silinecek->setXKoordinatDbl(ui->tblSehirListe->item(seciliSatir,2)->text().toDouble());
        silinecek->setYKoordinatDbl(ui->tblSehirListe->item(seciliSatir,3)->text().toDouble());

        veritabani::getVeritabani()->sehirSil(silinecek);
        ui->tblSehirListe->removeRow(seciliSatir);

        QMessageBox::information(this,"Bilgilendirme","Seçilen Şehir Silindi.");

    }
}

void subeEkle::on_btnSehirGuncelle_clicked()
{
    if (ui->tblSehirListe->currentRow() == -1) {
        QMessageBox::information(this,"Bilgilendirme","Satır Seçiniz...");
    }else{
        int seciliSatir = ui->tblSehirListe->currentRow();
        sehir *guncelle = new sehir(this);
        guncelle->setKodStr(ui->tblSehirListe->item(seciliSatir,0)->text());
        guncelle->setAdiStr(ui->tblSehirListe->item(seciliSatir,1)->text());
        guncelle->setXKoordinatDbl(ui->tblSehirListe->item(seciliSatir,2)->text().toDouble());
        guncelle->setYKoordinatDbl(ui->tblSehirListe->item(seciliSatir,3)->text().toDouble());

        veritabani::getVeritabani()->sehirGuncelle(guncelle);

        QMessageBox::information(this,"Bilgilendirme","Seçilen Şehir Güncellendi.");

    }
}


void subeEkle::on_btnSubeGuncelle_clicked()
{
    if (ui->tblSubeListe->currentRow() == -1 ) {
            QMessageBox::information(this,"Bilgilendirme","Satır Seçiniz...");
        }else{
        int seciliSatir = ui->tblSubeListe->currentRow();
        sube *guncelle = new sube(this);
        guncelle->setKodStr(ui->tblSubeListe->item(seciliSatir,0)->text());
        guncelle->setAdiStr(ui->tblSubeListe->item(seciliSatir,1)->text());
        guncelle->setTelStr(ui->tblSubeListe->item(seciliSatir,2)->text());
        guncelle->setMailStr(ui->tblSubeListe->item(seciliSatir,3)->text());
        guncelle->setSubeSehir(ui->tblSubeListe->item(seciliSatir,4)->text());

        veritabani::getVeritabani()->subeGuncelle(guncelle);

        QMessageBox::information(this,"Bilgilendirme","Seçilen Şube Güncellendi.");

        }
}

void subeEkle::on_btnSubeSil_clicked()
{
    if (ui->tblSubeListe->currentRow() == -1 ) {
            QMessageBox::information(this,"Bilgilendirme","Satır Seçiniz...");
        }else{
        int seciliSatir = ui->tblSubeListe->currentRow();
        sube *silinecek = new sube(this);
        silinecek->setKodStr(ui->tblSubeListe->item(seciliSatir,0)->text());
        silinecek->setAdiStr(ui->tblSubeListe->item(seciliSatir,1)->text());
        silinecek->setTelStr(ui->tblSubeListe->item(seciliSatir,2)->text());
        silinecek->setMailStr(ui->tblSubeListe->item(seciliSatir,3)->text());
        silinecek->setSubeSehir(ui->tblSubeListe->item(seciliSatir,4)->text());

        veritabani::getVeritabani()->subeSil(silinecek);
        ui->tblSubeListe->removeRow(seciliSatir);

        QMessageBox::information(this,"Bilgilendirme","Seçilen Şube Silindi.");

        }
}
