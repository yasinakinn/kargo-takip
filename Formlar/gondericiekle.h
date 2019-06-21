#ifndef GONDERICIEKLE_H
#define GONDERICIEKLE_H

#include <QMainWindow>
#include "gonderici.h"
#include "veritabani.h"
#include <QMap>

namespace Ui {
class gondericiEkle;
}

class gondericiEkle : public QWidget
{
    Q_OBJECT

public:
    explicit gondericiEkle(QWidget *parent = 0);
    ~gondericiEkle();
    gonderici *gondericiPtr;


    bool getGondericiEkleYeni() const;
    void setGondericiEkleYeni(bool value);

    QString gonderilen();

    void setGondericiPtr(gonderici *value);
    gonderici *getGondericiPtr() const;

signals:
    void gondericiDegisti(bool value);

private slots:
    void on_btn_geri_clicked();

    void on_btnKaydet_clicked();

private:
    Ui::gondericiEkle *ui;

    bool gondericiEkleYeni;

};

#endif // GONDERICIEKLE_H
