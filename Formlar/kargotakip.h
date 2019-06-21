#ifndef KARGOTAKIP_H
#define KARGOTAKIP_H

#include <QMainWindow>

namespace Ui {
class KargoTakip;
}

class KargoTakip : public QMainWindow
{
    Q_OBJECT

public:
    explicit KargoTakip(QWidget *parent = 0);
    ~KargoTakip();

private slots:
    void on_btnGondericiEkle_clicked();

    void on_brnSubeEkle_clicked();

    void on_btnGondericiAra_clicked();

    void on_btnKargoTeslim_clicked();

    void on_btnKargoHesapla_clicked();

    void on_btnCikis_clicked();

private:
    Ui::KargoTakip *ui;
};

#endif // KARGOTAKIP_H
