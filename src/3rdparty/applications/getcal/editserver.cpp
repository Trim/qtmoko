#include "editserver.h"

EditServer::EditServer(QWidget *parent, Qt::WFlags f) :
    QWidget(parent, f)
{
    setupUi(this);
    qRegisterMetaType<IcalServer>("IcalServer");
}

EditServer::~EditServer(){
    delete this;
}

void EditServer::addServer(){
    _server = new IcalServer(QString("A unique name for this server"), QString("http://example.org"));
    QObject::connect(uiServerNameLine, SIGNAL(textChanged(QString)), _server, SLOT(setServerName(QString)));
    QObject::connect(uiServerAddressLine, SIGNAL(textChanged(QString)), _server, SLOT(setServerAddress(QString)));
    QObject::connect(uiUserNameLine, SIGNAL(textChanged(QString)), _server, SLOT(setUserName(QString)));
    QObject::connect(uiUserPassLine, SIGNAL(textChanged(QString)), _server, SLOT(setUserPass(QString)));
    updateUI();
}

void EditServer::updateUI(){
    uiServerNameLine->clear();
    uiServerNameLine->insert(_server->getServerName());

    uiServerAddressLine->clear();
    uiServerAddressLine->insert(_server->getServerAddress());
    if(!isVisible()){
        showMaximized();
    }
}

void EditServer::closeEvent(QCloseEvent *event){
    emit endEdit(_server);
    QWidget::closeEvent(event);
}
