#ifndef PRESSFRAME_H
#define PRESSFRAME_H

#include <QFrame>
#include <QWidget>
#include <QMouseEvent>

class PressFrame : public QFrame
{

    Q_OBJECT

public:
    explicit PressFrame(QWidget *parent = 0);

protected:
    void mouseMoveEvent(QMouseEvent* event);


};

#endif // PRESSFRAME_H
