#include "serversettings.h"

ServerSettings::ServerSettings(QWidget *parent, Qt::WFlags f) :
    QWidget(parent, f)
{
    setupUi(this);
    qRegisterMetaType<IcalServer>("IcalServer");

    _settings = new QSettings("Trolltech", "Getcal");
    _serverMap = new QMap<QString,IcalServer>();
    _editServer = new EditServer(parent, f);

    readServerSettings();

    QMenu *menu = QSoftMenuBar::menuFor(this);
    menu->addAction("Add server", _editServer, SLOT(addServer()));
    menu->addAction("Edit server", this, SLOT(editServer()));
    QObject::connect(this, SIGNAL(editClickedServer(IcalServer *)), _editServer, SLOT(editServer(IcalServer*)));
    QObject::connect(_editServer, SIGNAL(endEdit(IcalServer*)), this, SLOT(setServer(IcalServer*)));
    QObject::connect(uiSaveConfigButton, SIGNAL(clicked()), this, SLOT(saveSettings()));
}

ServerSettings::~ServerSettings(){
    delete this;
}

void ServerSettings::editServer(){
    QListWidgetItem *serverItem = uiServerList->currentItem();
    QString serverName = serverItem->text();
    IcalServer server = _serverMap->value(serverName);
    emit editClickedServer(&server);
}

/* Create widget only when needed */
void ServerSettings::openSettings(){
    if(!isVisible()){
        showMaximized();
    }
}

void ServerSettings::setServer(IcalServer *server){
    _serverMap->insert(server->getServerName(), *server);
    uiServerList->clear();
    QString srvName;
    foreach(srvName, _serverMap->keys()){
        uiServerList->addItem(srvName);
    }
    saveSettings();
}

/* Save all server settings */
void ServerSettings::saveSettings(){
    _settings->beginGroup(QString("servers"));
    QString srvName;
    for(QMap<QString, IcalServer>::iterator it=_serverMap->begin(); it!=_serverMap->end(); ++it){
        IcalServer& srv = it.value();
        _settings->beginGroup(it.key());
        _settings->setValue("serveraddress", srv.getServerAddress());
        _settings->setValue("username", srv.getUserName());
        _settings->setValue("password", srv.getPassword());
        _settings->setValue("calendars", srv.getCalendars());
        _settings->endGroup();
    }
    _settings->endGroup();
    qDebug()<< "Settings saved";
}

/* Read all server from settings */
void ServerSettings::readServerSettings(){
    _settings->beginGroup(QString("servers"));
    QStringList serverNames = _settings->childGroups();
    foreach(QString srvName, serverNames){
        _settings->beginGroup(srvName);
        QString srvAddress=(_settings->value("serveraddress")).toString();
        QString usrName=(_settings->value("username")).toString();
        QString usrPass=(_settings->value("password")).toString();
        QStringList calendars = (_settings->value("calendars")).toStringList();
        _settings->endGroup();
        IcalServer* tmp = new IcalServer(srvName, srvAddress, usrName, usrPass, calendars);
        _serverMap->insert(srvName, *tmp);
        QListWidgetItem * item = new QListWidgetItem(srvName);
        uiServerList->addItem(item);
    }
    _settings->endGroup();
}
