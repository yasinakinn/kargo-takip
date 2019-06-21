#include "gondericiekle.h"
#include "ui_gondericiekle.h"
#include "kargotakip.h"
#include "kargoteslim.h"
#include "QMessageBox"

gondericiEkle::gondericiEkle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gondericiEkle)
{
    ui->setupUi(this);
    QPalette* palette = new QPalette();
    palette->setBrush(QPalette::Background,*(new QBrush(*(new QPixmap(":/background/background.png")))));
    setPalette(*palette);

    QList<sube *> subeGelen = veritabani::getVeritabani()->subeTumuAra();
    if(subeGelen.count() != 0){
        for(int i = 0; i < subeGelen.count(); i++){
            ui->cmbxSubeList->addItem(subeGelen[i]->getAdiStr());
        }
    }
}

gondericiEkle::~gondericiEkle()
{
    delete ui;
}

gonderici *gondericiEkle::getGondericiPtr() const{
    return gondericiPtr;
}

void gondericiEkle::on_btn_geri_clicked()
{
    close();
    KargoTakip* s = new KargoTakip();
    s->show();
}

void gondericiEkle::on_btnKaydet_clicked()
{
    gonderici *ekle = new gonderici;
    if(veritabani::getVeritabani()->gondericiTumuAra().count() == 0) {
        ekle->setAdStr(ui->lnAd->text());
        ekle->setSoyadStr(ui->lnSoyad->text());
        ekle->setAdresStr(ui->lnAdres->text());
        ekle->setTelStr(ui->lnCepNo->text());
        ekle->setMailStr(ui->lnMail->text());
        ekle->setGondericiSube(ui->cmbxSubeList->currentText());
        ekle->setKodStr("100000");
        veritabani::getVeritabani()->gondericiEkle(ekle);

    }else{
        ekle->setAdStr(ui->lnAd->text());
        ekle->setSoyadStr(ui->lnSoyad->text());
        ekle->setAdresStr(ui->lnAdres->text());
        ekle->setTelStr(ui->lnCepNo->text());
        ekle->setMailStr(ui->lnMail->text());
        ekle->setGondericiSube(ui->cmbxSubeList->currentText());
        ekle->setKodStr(QString::number(veritabani::getVeritabani()->gondericiTumuAra().last()->getKodStr().toInt()+ 1));
        veritabani::getVeritabani()->gondericiEkle(ekle);
    }

    gondericiPtr =ekle;

    if(ui->lnAd->text()==NULL || ui->lnSoyad->text()==NULL || ui->lnAdres->text()==NULL
            || ui->lnCepNo->text()==NULL || ui->lnMail->text()==NULL || ui->cmbxSubeList->currentText()==NULL )
    {
        QMessageBox::warning(this,"Hata!","Boş alanları doldurmanız gerekli.");
    }
    else
    {
    QMessageBox::information(this,"Tebrikler!","Bilgileriniz kaydedildi.Kargo Teslime yönlendiriliyorsunuz.");
    close();
    kargoTeslim* a = new kargoTeslim(ekle,NULL);
    a->show();
    }
}

bool gondericiEkle::getGondericiEkleYeni() const
{
    return gondericiEkleYeni;
}

void gondericiEkle::setGondericiEkleYeni(bool value)
{
    gondericiEkleYeni = value;
    gondericiDegisti(gondericiEkleYeni);
}

QString gondericiEkle::gonderilen()
{
    return gondericiPtr->getKodStr();
}

void gondericiEkle::setGondericiPtr(gonderici *value)
{
    gondericiPtr = value;
}
