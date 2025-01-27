#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QApplication>
#include <QDesktopWidget>
#include <QWidget>
#include <QScreen>
#include <QStateMachine>
#include <QState>
#include <QPropertyAnimation>
#include <QDBusConnection>
#include "dbus/dbushidestatemanager.h"
#include "dbus/dbusdocksetting.h"
#include "dbus/dbusdisplay.h"
#include "controller/dockmodedata.h"
#include "panel/panel.h"
#include "panel/dockpanel.h"

const QString DBUS_PATH = "/com/deepin/dde/dock";
const QString DBUS_NAME = "com.deepin.dde.dock";

class DockUIDbus;
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void loadResources();

protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

private:
    void hideDock();
    void onPanelSizeChanged();
    void onDockModeChanged();
    void updateXcbStructPartial();
    void initHideStateManager();

private slots:
    void showDock();
    void updatePosition();

private:
#ifdef NEW_DOCK_LAYOUT
    DockPanel *m_mainPanel = NULL;
#else
    Panel *m_mainPanel = NULL;
#endif
    bool m_hasHidden = false;
    DockModeData * m_dmd = DockModeData::instance();
    DBusHideStateManager *m_dhsm = NULL;
    DBusDisplay *m_display = NULL;
};

class DockUIDbus : public QDBusAbstractAdaptor {
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.deepin.dde.dock")

public:
    DockUIDbus(MainWidget* parent);
    ~DockUIDbus();

    Q_SLOT qulonglong Xid();
private:
    MainWidget* m_parent;
};

#endif // MAINWIDGET_H
