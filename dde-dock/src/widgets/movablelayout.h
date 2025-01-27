#ifndef MOVABLELAYOUT_H
#define MOVABLELAYOUT_H

#include <QFrame>
#include <QList>
#include <QDragEnterEvent>
#include <QHBoxLayout>
#include <QEasingCurve>

class QDrag;
class QPropertyAnimation;

class MovableLayout : public QFrame
{
    Q_OBJECT
public:
    enum MoveDirection {
        MoveLeftToRight,
        MoveRightToLeft,
        MoveTopToBottom,
        MoveBottomToTop,
        MoveUnknow
    };

    explicit MovableLayout(QWidget *parent = 0);
    explicit MovableLayout(QBoxLayout::Direction direction, QWidget *parent = 0);

    bool getAutoResize() const;
    int count() const;
    int hoverIndex() const;
    int getLayoutSpacing() const;
    int getAnimationDuration() const;
    int indexOf(QWidget * const widget, int from = 0) const;

    QWidget *dragingWidget();
    QWidget *widget(int index) const;
    QList<QWidget *> widgets() const;
    QSize getDefaultSpacingItemSize() const;
    QBoxLayout::Direction direction() const;
    QEasingCurve::Type getAnimationCurve() const;

    void restoreDragingWidget();
    void removeWidget(int index);
    void addWidget(QWidget *widget);
    void removeWidget(QWidget *widget);
    void insertWidget(int index, QWidget *widget);

    void setDuration(int v);
    void setLayoutSpacing(int spacing);
    void setAutoResize(bool autoResize);
    void setEasingCurve(QEasingCurve::Type curve);
    void setAnimationDuration(int animationDuration);
    void setDirection(QBoxLayout::Direction direction);
    void setAnimationCurve(const QEasingCurve::Type &animationCurve);
    void setDefaultSpacingItemSize(const QSize &defaultSpacingItemSize);

signals:
    void dragEntered();
    void startDrag(QDrag*);
    void drop(QDropEvent *event);
    void requestSpacingItemsDestroy();
    void sizeChanged(QResizeEvent *event);

private:
    bool event(QEvent *e);
    void mouseMoveEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void storeDragingWidget();
    void handleDrag(const QPoint &pos);
    void updateCurrentHoverInfo(int index, const QPoint &pos);
    void addSpacingItem(QWidget *souce, MoveDirection md, const QSize &size);
    void insertSpacingItemToLayout(int index, const QSize &size, bool immediately = false);
    int getHoverIndextByPos(const QPoint &pos);
    MoveDirection getVMoveDirection(int index, const QPoint &pos);
    MoveDirection getHMoveDirection(int index, const QPoint &pos);

private:
    int m_lastHoverIndex;
    int m_animationDuration;
    bool m_hoverToSpacing;
    bool m_autoResize;
    QWidget *m_draginItem;
    QHBoxLayout *m_layout;
    QList<QWidget *> m_widgetList;
    QSize m_defaultSpacingItemSize;
    MoveDirection m_vMoveDirection;
    MoveDirection m_hMoveDirection;
    QEasingCurve::Type m_animationCurve;
};

#endif // MOVABLELAYOUT_H
