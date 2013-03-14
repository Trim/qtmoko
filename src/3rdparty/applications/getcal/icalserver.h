#ifndef ICALSERVER_H
#define ICALSERVER_H

#include <QString>
#include <QStringList>

class IcalServer {
private:
    QString _serverName;
    QString _serverAddress;
    QString _userName;
    QString _userPassword;
    QStringList * _calendars;

public:
    /* Constructor : we need at least the server address (the name is for the GUI) */
    IcalServer(QString serverName, QString serverAddress);
    ~IcalServer();

    /* We can set a login if needed */
    void setLogin(QString userName, QString userPassword);
    void getLogin(QString * name, QString * password);

    /* Manage calendars */
    void addCalendar(QString calendar);
    void removeCalendar(QString calendar);
    void updateCalenar(QString oldCalendar, QString newCalendar);
    QStringList * getCalendars();
    QString getServerName();
    QString getServerAddress();

    /* We'll need to check if configuration is acceptable (http://, server reachable, good http response,...)*/
    bool checkConfig();
};
#endif // ICALSERVER_H
