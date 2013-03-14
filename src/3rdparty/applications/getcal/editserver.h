#ifndef EDITSERVER_H
#define EDITSERVER_H

#include <QWidget>
#include "ui_editserver.h"
#include "icalserver.h"

class EditServer : public QWidget, public Ui_EditServer
{
    Q_OBJECT

private:
    IcalServer *server;
    void updateUI();

public:
    explicit EditServer(QWidget *parent = 0, Qt::WFlags f=0);
    ~EditServer();
        
public slots:
    void addServer();
};

#endif // EDITSERVER_H
