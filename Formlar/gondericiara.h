#ifndef GONDERICIARA_H
#define GONDERICIARA_H

#include <QWidget>

namespace Ui {
class gondericiAra;
}

class gondericiAra : public QWidget
{
    Q_OBJECT

public:
    explicit gondericiAra(QWidget *parent = 0);
    ~gondericiAra();

private slots:
    void on_btnAnaSayfa_clicked();

    void on_btnKodAra_clicked();

    void on_btnAdAra_clicked();

    void on_btnTumu_clicked();

    void on_btnKargoHazirla_clicked();

    void on_btnEkle_clicked();

    void on_btnSil_clicked();

    void on_btnGuncelle_clicked();

private:
    Ui::gondericiAra *ui;
};

#endif // GONDERICIARA_H
