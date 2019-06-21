#include "kargohesapla.h"
#include "ui_kargohesapla.h"
#include "kargotakip.h"
#include "veritabani.h"
#include "urun.h"
#include <QMessageBox>

kargoHesapla::kargoHesapla(urun* a, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kargoHesapla)
{
    ui->setupUi(this);
    QPalette* palette = new QPalette();
    palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap(":/background/background.png")))));
    setPalette(*palette);

    if (a != NULL) {
        if (a->getHacimDbl() == 0 ) {
            ui->lnHacim->setText(QString::number(a->getHacimDbl()));
        }
        if (a->getAgirliDbl() == 0) {
            ui->lnAgirlik->setText(QString::number(a->getAgirliDbl()));
        }
    }
}

kargoHesapla::~kargoHesapla()
{
    delete ui;
}

void kargoHesapla::on_btnGeri_clicked()
{
    close();
    KargoTakip* s = new KargoTakip();
    s->show();
}

void kargoHesapla::on_btnHacim_clicked()
{
    if(ui->lnHacim->text().toDouble()/3 > ui->lnAgirlik->text().toDouble()){
        double fiyat = ui->lnHacim->text().toDouble()/3*ui->lnFiyatBirim->text().toDouble();
        ui->lnUcret->setText(QString::number(fiyat));
    }else if(ui->lnAgirlik->text().toDouble() > ui->lnHacim->text().toDouble()/3){
        double fiyat = ui->lnAgirlik->text().toDouble()*ui->lnFiyatBirim->text().toDouble();
        ui->lnUcret->setText(QString::number(fiyat));
    }
}
