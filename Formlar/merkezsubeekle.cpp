#include "merkezsubeekle.h"
#include "ui_merkezsubeekle.h"
#include "merkezsube.h"
#include "veritabani.h"
#include "subeekle.h"

merkezSubeEkle::merkezSubeEkle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::merkezSubeEkle)
{
    ui->setupUi(this);

    QPalette* palette = new QPalette();
    palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap(":/background/background.png")))));
    setPalette(*palette);

    QList<sube *> subeGelen = veritabani::getVeritabani()->subeTumuAra();
    if (subeGelen.count() != 0) {
        for (int i = 0; i < subeGelen.count(); ++i) {
            ui->cmbSube->addItem(subeGelen[i]->getAdiStr());
        }
    }
}

merkezSubeEkle::~merkezSubeEkle()
{
    delete ui;
}

void merkezSubeEkle::on_btnEkle_clicked()
{
    merkezSube *ekle = new merkezSube(this);
    QString kod;
    if (ui->cmbMerkez->currentText() == "Ana Merkez") {
        kod = "0";
    }
    else if (ui->cmbMerkez->currentText() == "Bölge Merkez 1") {
        kod = "1";
    }
    else if (ui->cmbMerkez->currentText() == "Bölge Merkez 2") {
        kod = "2";
    }
    else if (ui->cmbMerkez->currentText() == "Bölge Merkez 3") {
        kod = "3";
    }
    else if (ui->cmbMerkez->currentText() == "Bölge Merkez 4") {
        kod = "4";
    }

    ekle->setKod(kod);
    ekle->setDurum(1);
    ekle->setSubeKod(veritabani::getVeritabani()->subeAdAra(ui->cmbSube->currentText()).first()->getKodStr());

    veritabani::getVeritabani()->merkezEkle(ekle);
}

void merkezSubeEkle::on_btnTumu_clicked()
{
    QList<merkezSube *> gelen = veritabani::getVeritabani()->merkezSubeTumuAra();

    if (gelen.count()!=0) {
        ui->tblSubeListele->setRowCount(gelen.count());

        for (int i = 0; i < gelen.count(); ++i) {
            QTableWidgetItem *kod = new QTableWidgetItem();
            QTableWidgetItem *durum = new QTableWidgetItem();
            QTableWidgetItem *sube = new QTableWidgetItem();

            kod->setText(gelen[i]->getKod());
            durum->setText(QString::number(gelen[i]->getDurum()));
            sube->setText(gelen[i]->getSubeKod());

            ui->tblSubeListele->setItem(i,0,kod);
            ui->tblSubeListele->setItem(i,1,durum);
            ui->tblSubeListele->setItem(i,2,sube);
        }

    }
}

void merkezSubeEkle::on_btnGuncelle_clicked()
{
    int seciliSatir = ui->tblSubeListele->currentRow();
    merkezSube *guncelle = new merkezSube(this);
    guncelle->setKod(ui->tblSubeListele->item(seciliSatir,0)->text());
    guncelle->setDurum(ui->tblSubeListele->item(seciliSatir,1)->text().toInt());
    guncelle->setSubeKod(ui->tblSubeListele->item(seciliSatir,2)->text());

    veritabani::getVeritabani()->merkezGuncelle(guncelle);
}


void merkezSubeEkle::on_btnGeri_clicked()
{
    close();
    subeEkle *s = new subeEkle;
    s->show();
}

void merkezSubeEkle::on_btnSil_clicked()
{
    int seciliSatir = ui->tblSubeListele->currentRow();
    merkezSube *sil = new merkezSube(this);
    sil->setKod(ui->tblSubeListele->item(seciliSatir,0)->text());
    sil->setDurum(ui->tblSubeListele->item(seciliSatir,1)->text().toInt());
    sil->setSubeKod(ui->tblSubeListele->item(seciliSatir,2)->text());

    veritabani::getVeritabani()->merkezSil(sil);
    ui->tblSubeListele->removeRow(seciliSatir);
}
