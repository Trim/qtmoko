#include "icalserver.h"

IcalServer::IcalServer(QString serverName, QString serverAddress)
{
    _serverName = serverName;
    _serverAddress = serverAddress;
    _calendars = new QStringList();
}

IcalServer::~IcalServer(){
}

void IcalServer::setLogin(QString userName, QString userPassword){
    _userName = userName;
    _userPassword = userPassword;
}

void IcalServer::getLogin(QString *name, QString *password){
    name = &_userName;
    password = &_userPassword;
}

void IcalServer::addCalendar(QString calendar){
    _calendars->append(calendar);
}

void IcalServer::removeCalendar(QString calendar){
    _calendars->removeAll(calendar);
}

void IcalServer::updateCalenar(QString oldCalendar, QString newCalendar){
    _calendars->replace(_calendars->indexOf(oldCalendar), newCalendar);
}

QStringList * IcalServer::getCalendars(){
    return _calendars;
}

bool IcalServer::checkConfig(){
    return true;
}

QString IcalServer::getServerName(){
    return _serverName;
}

QString IcalServer::getServerAddress(){
    return _serverAddress;
}
