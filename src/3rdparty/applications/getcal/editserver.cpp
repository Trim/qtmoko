#include "editserver.h"

EditServer::EditServer(QWidget *parent, Qt::WFlags f) :
    QWidget(parent, f)
{
    setupUi(this);
    show();
}

EditServer::~EditServer(){
    delete this;
}

void EditServer::addServer(){
    server = new IcalServer(QString("A unique name for this server"), QString("http://example.org"));
    updateUI();
}

void EditServer::updateUI(){
    serverNameLineEdit->clear();
    serverNameLineEdit->insert(server->getServerName());

    serverUrlLineEdit->clear();
    serverUrlLineEdit->insert(server->getServerAddress());
}
