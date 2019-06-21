#ifndef SUBEEKLE_H
#define SUBEEKLE_H

#include <QWidget>

namespace Ui {
class subeEkle;
}

class subeEkle : public QWidget
{
    Q_OBJECT

public:
    explicit subeEkle(QWidget *parent = 0);
    ~subeEkle();

private slots:
    void on_btnGeri_clicked();

    void on_btnMerkezSube_clicked();

    void on_btn_sehirEkle_clicked();

    void on_btnSubeEkle_clicked();

    void on_btnSehirTumu_clicked();

    void on_btnSubeTumu_clicked();

    void on_btnSehirSil_clicked();

    void on_btnSehirGuncelle_clicked();

    void on_btnSubeGuncelle_clicked();

    void on_btnSubeSil_clicked();

private:
    Ui::subeEkle *ui;
};

#endif // SUBEEKLE_H
