/*
 * This file was generated by qfsodbusxml2cpp version 0.7
 * Command line was: qfsodbusxml2cpp -p qfsocontextmanager -c QFsoContextManager specs/xml/org.freesmartphone.Context.Manager.xml
 *
 * qfsodbusxml2cpp is Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef QFSOCONTEXTMANAGER_H
#define QFSOCONTEXTMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.freesmartphone.Context.Manager
 */
class QFsoContextManager: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freesmartphone.Context.Manager"; }

public:
    QFsoContextManager(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~QFsoContextManager();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> SubscribeLocationUpdates(const QString &desired_accuracy)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(desired_accuracy);
        return asyncCallWithArgumentList(QLatin1String("SubscribeLocationUpdates"), argumentList);
    }

    inline QDBusPendingReply<> UnsubscribeLocationUpdates()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("UnsubscribeLocationUpdates"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

namespace org {
  namespace freesmartphone {
    namespace Context {
      typedef ::QFsoContextManager Manager;
    }
  }
}
#endif
