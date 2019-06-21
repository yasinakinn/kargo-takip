#include "guzergaholustur.h"
#include "ui_guzergaholustur.h"
#include "veritabani.h"
#include "gondericiara.h"
#include "QMessageBox"

guzergahOlustur::guzergahOlustur(urun *gelen, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::guzergahOlustur)
{
    ui->setupUi(this);
    QPalette* palette = new QPalette();
    palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap(":/background/background.png")))));
    setPalette(*palette);

    ui->lnUrunKod->setText(gelen->getKodStr());
}

guzergahOlustur::~guzergahOlustur()
{
    delete ui;
}

void guzergahOlustur::on_btnOlustur_clicked()
{
    if (ui->lnUrunKod->text() == NULL) {
        QMessageBox::information(this,"Bilgilendirme","Ürün kodu girilmedi.");
    }else {
        QList<sehir *> gelen = veritabani::getVeritabani()->duzergah(ui->lnUrunKod->text());

        if (gelen.count() != 0) {
            ui->tblListele->setRowCount(gelen.count());
            for (int i = 0; i < gelen.count(); ++i) {
                QTableWidgetItem *kodSatir = new QTableWidgetItem();
                QTableWidgetItem *adSatir = new QTableWidgetItem();
                QTableWidgetItem *xSatir = new QTableWidgetItem();
                QTableWidgetItem *ySatir = new QTableWidgetItem();

                xSatir->setText(QString::number(gelen[i]->getXKoordinatDbl()));
                ySatir->setText(QString::number(gelen[i]->getYKoordinatDbl()));
                adSatir->setText(gelen[i]->getAdiStr());
                kodSatir->setText(gelen[i]->getKodStr());

                ui->tblListele->setItem(i,0,kodSatir);
                ui->tblListele->setItem(i,1,adSatir);
                ui->tblListele->setItem(i,2,xSatir);
                ui->tblListele->setItem(i,3,ySatir);

            }

        }
    }
}

void guzergahOlustur::on_btnGeri_clicked()
{
    close();
    gondericiAra * geri = new gondericiAra;
    geri->show();
}
