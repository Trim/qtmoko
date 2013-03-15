#include "editserver.h"

EditServer::EditServer(QWidget *parent, Qt::WFlags f) :
    QWidget(parent, f)
{
    setupUi(this);
    qRegisterMetaType<IcalServer>("IcalServer");
    _server = new IcalServer();
    QObject::connect(serverNameLine, SIGNAL(textChanged(QString)), _server, SLOT(setServerName(QString)));
    QObject::connect(serverAddressLine, SIGNAL(textChanged(QString)), _server, SLOT(setServerAddress(QString)));
    QObject::connect(userNameLine, SIGNAL(textChanged(QString)), _server, SLOT(setUserName(QString)));
    QObject::connect(userPassLine, SIGNAL(textChanged(QString)), _server, SLOT(setUserPass(QString)));
}

EditServer::~EditServer(){
    delete this;
}

void EditServer::addServer(){
    _server = new IcalServer(QString("A unique name for this server"), QString("http://example.org"));
    updateUI();
}

void EditServer::updateUI(){
    serverNameLine->clear();
    serverNameLine->insert(_server->getServerName());

    serverAddressLine->clear();
    serverAddressLine->insert(_server->getServerAddress());
    if(!isVisible()){
        showMaximized();
    }
}

bool EditServer::close(){
    emit endEdit(_server);
    return true;
}
