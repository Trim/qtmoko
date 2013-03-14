/****************************************************************************
**
** This file is part of the Qt Extended Opensource Package.
**
** Copyright (C) 2009 Trolltech ASA.
**
** Contact: Qt Extended Information (info@qtextended.org)
**
** This file may be used under the terms of the GNU General Public License
** version 2.0 as published by the Free Software Foundation and appearing
** in the file LICENSE.GPL included in the packaging of this file.
**
** Please review the following information to ensure GNU General Public
** Licensing requirements will be met:
**     http://www.fsf.org/licensing/licenses/info/GPLv2.html.
**
**
****************************************************************************/

#ifndef GETCAL_H
#define GETCAL_H
#include "ui_getcal.h"
#include "calsettings.h"
#include <QString>

class Getcal : public QWidget, public Ui_Getcal
{
    Q_OBJECT
private:
    CalSettings *winSettings;
public:
    Getcal( QWidget *parent = 0, Qt::WFlags f = 0 );
    ~Getcal();
};
#endif
