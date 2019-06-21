#ifndef MERKEZSUBE_H
#define MERKEZSUBE_H

#include <qstring.h>
#include <QObject>
#include "kutuphane_global.h"


class KUTUPHANESHARED_EXPORT merkezSube: public QObject
{

    Q_OBJECT
private:
    QString kod;
    int durum;
    QString subeKod;

public:
    explicit merkezSube(QObject *parent = 0);
    QString getKod() const;
    int getDurum() const;
    QString getSubeKod() const;

public slots:
    void setKod(const QString value);
    void setDurum(int value);
    void setSubeKod(const QString value);
signals:
    void updateKod(QString kod);
    void updateDurum(int durum);
    void updateSubeKod(QString subeKod);
};

#endif // MERKEZSUBE_H
