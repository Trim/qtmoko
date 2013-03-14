#ifndef CALSETTINGS_H
#define CALSETTINGS_H

#include <QSettings>
#include <QLinkedList>
#include <QWidget>
#include <QPushButton>

#include "icalserver.h"
#include "ui_calsettings.h"
#include "editserver.h"

class CalSettings : public QWidget, public Ui_CalSettings
{
    Q_OBJECT
private:
    QSettings * settings;
    EditServer * editServer;
    QWidget *_parent;
    Qt::WFlags _f;

public:
    CalSettings(QWidget *parent=0, Qt::WFlags f=0);
    ~CalSettings();
    QLinkedList<IcalServer> retrieveServers();
    void storeServers();

public slots:
    void openSettings();
};

#endif // CALSETTINGS_H
