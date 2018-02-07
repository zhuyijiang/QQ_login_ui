#include "presslabel.h"

#ifdef Q_OS_WIN
#pragma comment(lib, "user32.lib")
#include <qt_windows.h>
#endif

PressLabel::PressLabel(QWidget *parent)
    :QLabel(parent)
{

}

void PressLabel::mouseMoveEvent(QMouseEvent* event)
{
#ifdef Q_OS_WIN
if(ReleaseCapture()) {
    QWidget* pWindow = this->window();
    if(pWindow->isTopLevel())
        SendMessage(HWND(pWindow->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
}
event->ignore();
#else
#endif
}
