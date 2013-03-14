#include "calsettings.h"
#include "editserver.h"
#include <qsoftmenubar.h>
#include <QMenu>

CalSettings::CalSettings(QWidget *parent, Qt::WFlags f) :
    QWidget(parent, f)
    //QMainWindow(parent),
    //settingsUi(new Ui::CalSettings)
{
    //settingsUi->setupUi(this);
    settings = new QSettings("Trolltech", "Getcal");
    /*QMenu *menu = QSoftMenuBar::menuFor(this);
    menu->addAction("Add server", editServer, SLOT(openServerWindow()));*/
    editServer = new EditServer(parent, f);
    QObject::connect(addServerButton, SIGNAL(clicked), editServer, SLOT(addServer()));
}

CalSettings::~CalSettings(){
    delete this;
}

void CalSettings::openSettings(){
    setupUi(this);
    show();
}
