/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -c DBusMenuManager -p dbusmenumanager com.deepin.menu.Manager.xml
 *
 * qdbusxml2cpp is Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "dbusmenumanager.h"

/*
 * Implementation of interface class DBusMenuManager
 */

DBusMenuManager::DBusMenuManager(QObject *parent)
    : QDBusAbstractInterface(staticServerPath(), staticInterfacePath(), staticInterfaceName(), QDBusConnection::sessionBus(), parent)
{
}

DBusMenuManager::~DBusMenuManager()
{
}

