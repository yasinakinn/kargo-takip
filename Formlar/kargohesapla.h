#ifndef KARGOHESAPLA_H
#define KARGOHESAPLA_H

#include <QWidget>
#include "kargotakip.h"
#include "veritabani.h"
#include "urun.h"

namespace Ui {
class kargoHesapla;
}

class kargoHesapla : public QWidget
{
    Q_OBJECT

public:
    explicit kargoHesapla(urun *a, QWidget *parent = 0);
    ~kargoHesapla();

private slots:
    void on_btnGeri_clicked();

    void on_btnHacim_clicked();

private:
    Ui::kargoHesapla *ui;
};

#endif // KARGOHESAPLA_H
