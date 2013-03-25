#ifndef CALSETTINGS_H
#define CALSETTINGS_H

#include <QSettings>
#include <QMap>
#include <QStringList>
#include <QString>
#include <QDebug>

#include <qsoftmenubar.h>
#include <QMenu>
#include <QCoreApplication>

#include <QWidget>
#include <QListWidget>
#include <QPushButton>

#include "icalserver.h"
#include "ui_calsettings.h"
#include "editserver.h"

class CalSettings : public QWidget, public Ui_CalSettings
{
    Q_OBJECT
private:
    /* Settings */
    QSettings * _settings;
    QMap<QString, IcalServer> * _serverMap;
    EditServer * _editServer;

public:
    CalSettings(QWidget *parent=0, Qt::WFlags f=0);
    ~CalSettings();

public slots:
    void openSettings();
    void setServer(IcalServer *server);

private slots:
    void saveSettings();
};
#endif // CALSETTINGS_H
