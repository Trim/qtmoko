#include "icalserver.h"

IcalServer::IcalServer(const IcalServer& icalSrv){
    _serverName = icalSrv.getServerName();
    _serverAddress = icalSrv.getServerAddress();
    _userName = icalSrv.getUserName();
    _userPassword = icalSrv.getPassword();
    _calendars->clear();
    //_calendars=_calendars<<icalSrv.getCalendars();
}

IcalServer& IcalServer::operator=(const IcalServer& icalSrv) {
    if ( this == &icalSrv ) {
        return *this; //Self assignment : nothing to do
    }

    _serverName = icalSrv.getServerName();
    _serverAddress = icalSrv.getServerAddress();
    _userName = icalSrv.getUserName();
    _userPassword = icalSrv.getPassword();
    _calendars->clear();
    //_calendars=_calendars<<icalSrv.getCalendars();
    return *this;
}

IcalServer::IcalServer(QString serverName, QString serverAddress)
{
    _serverName = serverName;
    _serverAddress = serverAddress;
    _calendars = new QStringList();
}

IcalServer::IcalServer(){
}

IcalServer::~IcalServer(){
}

QString IcalServer::getUserName() const{
    return _userName;
}

QString IcalServer::getPassword() const{
    return _userPassword;
}

void IcalServer::removeCalendar(QString calendar){
    _calendars->removeAll(calendar);
}

void IcalServer::updateCalenar(QString oldCalendar, QString newCalendar){
    _calendars->replace(_calendars->indexOf(oldCalendar), newCalendar);
}

QStringList * IcalServer::getCalendars() const{
    return _calendars;
}

bool IcalServer::checkConfig(){
    return true;
}

QString IcalServer::getServerName() const{
    return _serverName;
}

QString IcalServer::getServerAddress() const{
    return _serverAddress;
}
