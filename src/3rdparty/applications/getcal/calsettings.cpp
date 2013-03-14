#include "calsettings.h"
#include "editserver.h"
#include <qsoftmenubar.h>
#include <QMenu>

CalSettings::CalSettings(QWidget *parent, Qt::WFlags f) :
    QWidget(parent, f)
{
    _parent=parent;
    _f=f;
    settings = new QSettings("Trolltech", "Getcal");
}

CalSettings::~CalSettings(){
    delete this;
}

/* Create widget only when needed */
void CalSettings::openSettings(){
    setupUi(this);
    QMenu *menu = QSoftMenuBar::menuFor(this);
    editServer = new EditServer(_parent, _f);
    menu->addAction("Add server", editServer, SLOT(openServerWindow()));
    showMaximized();
}
