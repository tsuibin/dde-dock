#ifndef MAINITEM_H
#define MAINITEM_H

#include <QLabel>
#include <QIcon>
#include <QPixmap>
#include <QDragEnterEvent>
#include <QProcess>
#include <QDebug>

#include "dialogs/confirmuninstalldialog.h"
#include "dialogs/cleartrashdialog.h"
#include "interfaces/dockconstants.h"
#include "dbus/dbusfiletrashmonitor.h"
#include "dbus/dbusfileoperations.h"
#include "dbus/dbusemptytrashjob.h"
#include "dbus/dbustrashjob.h"
#include "dbus/dbuslauncher.h"

class SignalManager : public QObject
{
    Q_OBJECT
public:
    static SignalManager * instance();

signals:
    void requestAppIconUpdate();

private:
    static SignalManager *m_signalManager;
    explicit SignalManager(QObject *parent = 0) : QObject(parent) {}
};

class MainItem : public QLabel
{
    Q_OBJECT
public:
    MainItem(QWidget *parent = 0);
    ~MainItem();

    void emptyTrash();

protected:
    void mousePressEvent(QMouseEvent * event);
    void dragEnterEvent(QDragEnterEvent *);
    void dragLeaveEvent(QDragLeaveEvent *);
    void dropEvent(QDropEvent * event);

private slots:
    void onRequestUpdateIcon();

private:
    QString getThemeIconPath(QString iconName);
    void updateIcon(bool isOpen);

    DBusFileOperations * m_dfo = new DBusFileOperations(this);
    DBusFileTrashMonitor * m_dftm = NULL;
    DBusLauncher * m_launcher = new DBusLauncher(this);
};

#endif // MAINITEM_H
