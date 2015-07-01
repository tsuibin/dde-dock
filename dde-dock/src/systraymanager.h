#ifndef SYSTRAYMANAGER_H
#define SYSTRAYMANAGER_H

#include <QObject>
#include "dockplugininterface.h"

class SystrayManager : public QObject
{
    Q_OBJECT
public:
    explicit SystrayManager(QObject *parent = 0);

    QList<AbstractDockItem*> trayIcons();

private:
    DockPluginInterface *m_plugin;

    void loadPlugin();
    void unloadPlugin();
};

#endif // SYSTRAYMANAGER_H
