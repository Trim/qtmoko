/*
 * This file was generated by qfsodbusxml2cpp version 0.7
 * Command line was: qfsodbusxml2cpp -p qfsopimcall -c QFsoPIMCall specs/xml/org.freesmartphone.PIM.Call.xml
 *
 * qfsodbusxml2cpp is Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef QFSOPIMCALL_H
#define QFSOPIMCALL_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.freesmartphone.PIM.Call
 */
class QFsoPIMCall: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.freesmartphone.PIM.Call"; }

public:
    QFsoPIMCall(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~QFsoPIMCall();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> Delete()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("Delete"), argumentList);
    }

    inline QDBusPendingReply<QVariantMap> GetContent()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetContent"), argumentList);
    }

    inline QDBusPendingReply<QVariantMap> GetMultipleFields(const QString &field_list)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(field_list);
        return asyncCallWithArgumentList(QLatin1String("GetMultipleFields"), argumentList);
    }

    inline QDBusPendingReply<QStringList> GetUsedBackends()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QLatin1String("GetUsedBackends"), argumentList);
    }

    inline QDBusPendingReply<> Update(const QVariantMap &call_data)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(call_data);
        return asyncCallWithArgumentList(QLatin1String("Update"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void CallDeleted();
    void CallUpdated(const QVariantMap &data);
};

namespace org {
  namespace freesmartphone {
    namespace PIM {
      typedef ::QFsoPIMCall Call;
    }
  }
}
#endif
