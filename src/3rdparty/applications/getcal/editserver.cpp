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

void EditServer::setConnections(){
    QObject::connect(uiServerNameLine, SIGNAL(textChanged(QString)), _server, SLOT(setServerName(QString)));
    QObject::connect(uiServerAddressLine, SIGNAL(textChanged(QString)), _server, SLOT(setServerAddress(QString)));
    QObject::connect(uiUserNameLine, SIGNAL(textChanged(QString)), _server, SLOT(setUserName(QString)));
    QObject::connect(uiUserPassLine, SIGNAL(textChanged(QString)), _server, SLOT(setUserPass(QString)));
    QObject::connect(uiAddCalendar, SIGNAL(clicked()), this, SLOT(addCalendar()));
}

void EditServer::addServer(){
    _server = new IcalServer(QString("A unique name for this server"), QString("http://example.org/"));
    _server->addCalendar("Your calendar");
    setConnections();
    updateUI();
}

void EditServer::editServer(IcalServer *server){
    _server = server;
    setConnections();
    updateUI();
}

void EditServer::addCalendar(){
    QString newCal = uiCalendarInput->text();
    if(newCal.length()!=0 && !uiCalendarList->contains(newCal)){
        uiCalendarList->addItem(newCal);
        _server->addCalendar(newCal);
    }
}

void EditServer::updateUI(){
    uiServerNameLine->clear();
    uiServerNameLine->insert(_server->getServerName());

    uiServerAddressLine->clear();
    uiServerAddressLine->insert(_server->getServerAddress());

    uiUserNameLine->clear();
    uiUserNameLine->insert(_server->getUserName());

    uiUserPassLine->clear();
    uiUserPassLine->insert(_server->getPassword());

    uiCalendarList->clear();
    uiCalendarList->addItems(_server->getCalendars());

    if(!isVisible()){
        showMaximized();
    }
}

void EditServer::closeEvent(QCloseEvent *event){
    emit endEdit(_server);
    QWidget::closeEvent(event);
}
