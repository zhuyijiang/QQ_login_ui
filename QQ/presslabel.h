#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H

#include <QLabel>
#include <QWidget>
#include <QMouseEvent>

class PressLabel : public QLabel
{
    Q_OBJECT

public:
    explicit PressLabel(QWidget *parent = 0);

protected:
    void mouseMoveEvent(QMouseEvent* event);
};


#endif // CUSTOMLABEL_H
