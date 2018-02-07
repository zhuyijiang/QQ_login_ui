#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>

class QTimer;

namespace Ui {
class Widget;
}

enum State {Clockwise, Counterclockwise};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_closeButton_clicked();
    void on_minButton_clicked();
    void on_setButton_clicked();
    void rotate();

    void on_okButton_clicked();

    void on_closeButton_2_clicked();

    void on_minButton_2_clicked();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Widget *ui;

    QPixmap currentMap;
    QPixmap nextMap;
    QTimer* timer;
    qreal real;
    State state;
};

#endif // WIDGET_H
