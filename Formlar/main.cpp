#include "kargotakip.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KargoTakip w;
    w.show();

    return a.exec();
}
