#ifndef ICALSERVER_H
#define ICALSERVER_H

#include <QString>
#include <QStringList>

class IcalServer: public QObject {
    Q_OBJECT

private:
    QString _serverName;
    QString _serverAddress;
    QString _userName;
    QString _userPassword;
    QStringList * _calendars;

public:
    /* Constructor : we need at least the server address (the name is for the GUI) */
    IcalServer();
    IcalServer(const IcalServer& icalSrv);
    IcalServer(QString serverName, QString serverAddress);
    ~IcalServer();
    IcalServer& operator=(const IcalServer& icalSrv);

    /* We can set a login if needed */
    QString getUserName() const;
    QString getPassword() const;

    /* Manage calendars */
    void removeCalendar(QString calendar);
    void updateCalenar(QString oldCalendar, QString newCalendar);
    QStringList * getCalendars() const;

    /* Get and modify server name and address */
    QString getServerName() const;
    QString getServerAddress() const;

    /* We'll need to check if configuration is acceptable (http://, server reachable, good http response,...)*/
    bool checkConfig();
};
#endif // ICALSERVER_H
