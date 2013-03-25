#include "calsettings.h"

CalSettings::CalSettings(QWidget *parent, Qt::WFlags f) :
    QWidget(parent, f)
{
    setupUi(this);
    qRegisterMetaType<IcalServer>("IcalServer");

    _settings = new QSettings("Trolltech", "Getcal");
    _serverMap = new QMap<QString,IcalServer>();
    _editServer = new EditServer(parent, f);

    QMenu *menu = QSoftMenuBar::menuFor(this);
    menu->addAction("Add server", _editServer, SLOT(addServer()));
    QObject::connect(_editServer, SIGNAL(endEdit(IcalServer*)), this, SLOT(setServer(IcalServer*)));
    QObject::connect(saveConfigButton, SIGNAL(clicked()), this, SLOT(saveSettings()));
}

CalSettings::~CalSettings(){
    delete this;
}

/* Create widget only when needed */
void CalSettings::openSettings(){
    if(!isVisible()){
        showMaximized();
    }
}

void CalSettings::setServer(IcalServer *server){
    _serverMap->insert(server->getServerName(), *server);
    serverList->clear();
    QString srvName;
    foreach(srvName, _serverMap->keys()){
        serverList->addItem(srvName);
    }
    saveSettings();
}

/* Save all server settings */
void CalSettings::saveSettings(){
    QString srvName;
    for(QMap<QString, IcalServer>::iterator it=_serverMap->begin(); it!=_serverMap->end(); ++it){
        IcalServer& srv = it.value();
        _settings->beginGroup(it.key());
        _settings->setValue("serveraddress", srv.getServerAddress());
        _settings->setValue("username", srv.getUserName());
        _settings->setValue("password", srv.getPassword());
        _settings->endGroup();
    }
}
