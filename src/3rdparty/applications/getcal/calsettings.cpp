#include "calsettings.h"
#include <qsoftmenubar.h>
#include <QMenu>
#include <QString>

CalSettings::CalSettings(QWidget *parent, Qt::WFlags f) :
    QWidget(parent, f)
{
    _parent=parent;
    _f=f;
    _settings = new QSettings("Trolltech", "Getcal");
}

CalSettings::~CalSettings(){
    delete this;
}

/* Create widget only when needed */
void CalSettings::openSettings(){
    setupUi(this);
    qRegisterMetaType<IcalServer>("IcalServer");
    QMenu *menu = QSoftMenuBar::menuFor(this);
    _editServer = new EditServer(_parent, _f);
    menu->addAction("Add server", _editServer, SLOT(addServer()));
    QObject::connect(_editServer, SIGNAL(endEdit(IcalServer*)), this, SLOT(setServer(IcalServer*)));
    showMaximized();
}

void CalSettings::setServer(IcalServer *server){
    _serverMap->insert(server->getServerName(), *server);
    serverList->clear();
    QString srvName;
    foreach(srvName, _serverMap->keys()){
        serverList->addItem(srvName);
    }
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
