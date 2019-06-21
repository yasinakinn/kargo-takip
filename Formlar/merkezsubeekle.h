#ifndef MERKEZSUBEEKLE_H
#define MERKEZSUBEEKLE_H

#include <QWidget>

namespace Ui {
class merkezSubeEkle;
}

class merkezSubeEkle : public QWidget
{
    Q_OBJECT

public:
    explicit merkezSubeEkle(QWidget *parent = 0);
    ~merkezSubeEkle();

private slots:
    void on_btnEkle_clicked();

    void on_btnTumu_clicked();

    void on_btnGuncelle_clicked();

    void on_btnSil_clicked();

    void on_btnGeri_clicked();

private:
    Ui::merkezSubeEkle *ui;
};

#endif // MERKEZSUBEEKLE_H
