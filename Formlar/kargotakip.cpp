#include "kargotakip.h"
#include "ui_kargotakip.h"
#include "gondericiekle.h"
#include "subeekle.h"
#include "gondericiara.h"
#include "kargoteslim.h"
#include "kargohesapla.h"

KargoTakip::KargoTakip(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KargoTakip)
{
    ui->setupUi(this);
    QPalette* palette = new QPalette();
    palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap(":/background/background.png")))));
    setPalette(*palette);
}

KargoTakip::~KargoTakip()
{
    delete ui;
}

void KargoTakip::on_btnGondericiEkle_clicked()
{
    close();
    gondericiEkle* s = new gondericiEkle();
    s->show();

}

void KargoTakip::on_brnSubeEkle_clicked()
{
    close();
    subeEkle* s = new subeEkle();
    s->show();
}

void KargoTakip::on_btnGondericiAra_clicked()
{
    close();
    gondericiAra* s = new gondericiAra();
    s->show();
}

void KargoTakip::on_btnKargoTeslim_clicked()
{
    close();
    kargoTeslim* s = new kargoTeslim(NULL,NULL);
    s->show();
}

void KargoTakip::on_btnKargoHesapla_clicked()
{
    close();
    kargoHesapla* s = new kargoHesapla(NULL,NULL);
    s->show();
}

void KargoTakip::on_btnCikis_clicked()
{
    close();
}

