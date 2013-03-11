#ifndef CALSETTINGS_H
#define CALSETTINGS_H

#include <QSettings>
#include <QLinkedList>
#include "icalserver.h"

class CalSettings
{
private:
    QSettings * settings;
public:
    CalSettings();
    QLinkedList<IcalServer> retrieveServers();
    storeServers(QLinkedList<IcalServer> servers);
};

#endif // CALSETTINGS_H
