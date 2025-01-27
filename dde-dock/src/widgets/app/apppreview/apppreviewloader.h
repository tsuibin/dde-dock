#ifndef APPPREVIEWLOADER_H
#define APPPREVIEWLOADER_H

#include <QWidget>
#include <QFrame>
#include <QImage>
#include <QStyle>
#include <QByteArray>

class Monitor;
class QPaintEvent;
class AppPreviewLoader : public QFrame
{
    Q_OBJECT
    Q_PROPERTY(bool isHover READ isHover WRITE setIsHover)
public:
    friend class Monitor;

    AppPreviewLoader(WId sourceWindow, QWidget *parent = 0);
    ~AppPreviewLoader();

    QByteArray imageData;

    bool isHover() const;
    void setIsHover(bool isHover);
    void requestUpdate();

protected:
    void paintEvent(QPaintEvent * event);

private:
    WId m_sourceWindow;

    Monitor * m_monitor;
    int m_borderWidth = 3;
    bool m_isHover = false;

    void installMonitor();
    void removeMonitor();
    void prepareRepaint();

};

#endif // APPPREVIEWLOADER_H
