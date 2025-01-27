#ifndef DOCKLAYOUT_H
#define DOCKLAYOUT_H

#include <QMap>
#include <QList>
#include <QCursor>
#include <QWidget>
#include <QJsonObject>
#include <QJsonDocument>
#include <QPropertyAnimation>

#include "appitem.h"
#include "controller/dockmodedata.h"
#include "dbus/dbusdockedappmanager.h"

class DockLayout : public QWidget
{
    Q_OBJECT
public:
    enum Direction{
        LeftToRight,
        TopToBottom
    };

    explicit DockLayout(QWidget *parent = 0);

    void addItem(AbstractDockItem *item, bool delayShow = true);
    void appendItem(AbstractDockItem *item, bool delayShow = true);
    void insertItem(AbstractDockItem *item, int index, bool delayShow = true);
    void moveItem(int from, int to);
    void removeItem(int index);
    void removeItem(AbstractDockItem *item);
    void setSpacing(qreal spacing);
    void setVerticalAlignment(Qt::Alignment value);
    void setSortDirection(DockLayout::Direction value);

    int indexOf(AbstractDockItem *item) const;
    int indexOf(int x,int y) const;
    int getContentsWidth();
    int getItemCount() const;
    QList<AbstractDockItem *> getItemList() const;
    AbstractDockItem *getDraggingItem() const;

    int addItemDelayInterval() const;
    void setaddItemDelayInterval(int addItemDelayInterval);

    int removeItemDelayInterval() const;
    void setRemoveItemDelayInterval(int removeItemDelayInterval);

signals:
    void startDrag();
    void itemDropped();
    void contentsWidthChange();
    void frameUpdate();
    void itemDocking(QString id);
    void itemHoverableChange(bool hoverable);

public slots:
    void removeSpacingItem();
    void restoreTmpItem();
    void clearTmpItem();
    void relayout();

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private slots:
    void slotItemDrag();
    void slotItemRelease();
    void slotItemEntered(QDragEnterEvent *event);
    void slotItemExited(QDragLeaveEvent *event);
    void slotAnimationFinish();

private:
    void sortLeftToRight();
    void sortTopToBottom();
    void leftToRightMove(int hoverIndex);
    void topToBottomMove(int hoverIndex);
    void addSpacingItem();
    void dragoutFromLayout(int index);

    int spacingItemWidth() const;
    int spacingItemIndex() const;
    int animatingItemCount();
    QStringList itemsIdList() const;

private:
    QList<AbstractDockItem *> m_appList;
    QMap<AbstractDockItem *,int> m_dragItemMap;//only one item inside
    DBusDockedAppManager *m_ddam = new DBusDockedAppManager(this);

    Qt::Alignment m_verticalAlignment = Qt::AlignVCenter;
    DockLayout::Direction m_sortDirection = DockLayout::LeftToRight;

    qreal m_itemSpacing = 10;
    QPoint m_lastPost = QPoint(0,0);
    bool m_movingLeftward = true;
    int m_lastHoverIndex = -1;
    int m_addItemDelayInterval = 500;
    int m_removeItemDelayInterval = 500;

    const int MOVE_ANIMATION_DURATION_BASE = 300;
};

#endif // DOCKLAYOUT_H
