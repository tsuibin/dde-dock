/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -c DBusDockedAppManager -p dbusdockedappmanager dde.dock.DockedAppManager.xml
 *
 * qdbusxml2cpp is Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef DBUSDOCKEDAPPMANAGER_H_1436925098
#define DBUSDOCKEDAPPMANAGER_H_1436925098

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface dde.dock.DockedAppManager
 */
class DBusDockedAppManager: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticServerPath()
    { return "com.deepin.daemon.Dock"; }
    static inline const char *staticInterfacePath()
    { return "/dde/dock/DockedAppManager"; }
    static inline const char *staticInterfaceName()
    { return "dde.dock.DockedAppManager"; }

public:
    DBusDockedAppManager(QObject *parent = 0);

    ~DBusDockedAppManager();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<bool> Dock(const QString &in0, const QString &in1, const QString &in2, const QString &in3)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3);
        return asyncCallWithArgumentList(QStringLiteral("Dock"), argumentList);
    }

    inline QDBusPendingReply<QStringList> DockedAppList()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("DockedAppList"), argumentList);
    }

    inline QDBusPendingReply<bool> IsDocked(const QString &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("IsDocked"), argumentList);
    }

    inline QDBusPendingReply<bool> ReqeustDock(const QString &in0, const QString &in1, const QString &in2, const QString &in3)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0) << QVariant::fromValue(in1) << QVariant::fromValue(in2) << QVariant::fromValue(in3);
        return asyncCallWithArgumentList(QStringLiteral("ReqeustDock"), argumentList);
    }

    inline QDBusPendingReply<bool> RequestUndock(const QString &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("RequestUndock"), argumentList);
    }

    inline QDBusPendingReply<> Sort(const QStringList &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("Sort"), argumentList);
    }

    inline QDBusPendingReply<bool> Undock(const QString &in0)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(in0);
        return asyncCallWithArgumentList(QStringLiteral("Undock"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void Docked(const QString &in0);
    void Undocked(const QString &in0);
};

namespace dde {
  namespace dock {
    typedef ::DBusDockedAppManager DockedAppManager;
  }
}
#endif
