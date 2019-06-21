#ifndef GUZERGAHOLUSTUR_H
#define GUZERGAHOLUSTUR_H

#include <QWidget>
#include "urun.h"

namespace Ui {
class guzergahOlustur;
}

class guzergahOlustur : public QWidget
{
    Q_OBJECT

public:
    explicit guzergahOlustur(urun *gelen ,QWidget *parent = 0);
    ~guzergahOlustur();

private slots:
    void on_btnOlustur_clicked();

    void on_btnGeri_clicked();

private:
    Ui::guzergahOlustur *ui;
};

#endif // GUZERGAHOLUSTUR_H
