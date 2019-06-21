#ifndef KARGOTESLIM_H
#define KARGOTESLIM_H

#include <QMainWindow>
#include <QString>

#include "gondericiekle.h"

namespace Ui {
class kargoTeslim;
}

class kargoTeslim : public QWidget
{
    Q_OBJECT

public:
    explicit kargoTeslim(gonderici *a, alici *b, QWidget *parent = 0);
    ~kargoTeslim();
    gondericiEkle *gelen;

private slots:
    void on_btnGeri_clicked();

    void on_btnKaydet_clicked();

private:
    Ui::kargoTeslim *ui;
};

#endif // KARGOTESLIM_H
