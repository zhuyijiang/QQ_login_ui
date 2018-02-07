#include "widget.h"
#include "ui_widget.h"

#include <QMovie>
#include <QDialog>
#include <QPixmap>
#include <QPainter>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->frame_2->setVisible(false);

    QMovie* movie = new QMovie(this);
    movie->setFileName(tr(":/icon/Animation"));
    movie->setScaledSize(ui->Animation->size());
    ui->Animation->setMovie(movie);
    movie->setScaledSize(ui->Animation_2->size());
    ui->Animation_2->setMovie(movie);
    movie->start();

    currentMap = QPixmap(ui->frame->size());
    nextMap = QPixmap(ui->frame_2->size());
    ui->frame->render(&currentMap);
    ui->frame_2->render(&nextMap);

    timer = new QTimer(this);
    timer->setInterval(25);
    connect(timer, &QTimer::timeout, this, &Widget::rotate);

    //setStyleSheet("background:transparent;");
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_closeButton_clicked()
{
    qApp->quit();
}

void Widget::on_minButton_clicked()
{
    QWidget* pWindow = this->window();
    if(pWindow->isTopLevel())
        pWindow->showMinimized();
}

void Widget::on_setButton_clicked()
{
    real = 0;
    state = Clockwise;
    ui->frame->setVisible(false);
    timer->start();
}

void Widget::on_okButton_clicked()
{
    real = 180;
    state = Counterclockwise;
    ui->frame_2->setVisible(false);
    timer->start();
}

void Widget::on_closeButton_2_clicked()
{
    qApp->quit();
}

void Widget::on_minButton_2_clicked()
{
    QWidget* pWindow = this->window();
    if(pWindow->isTopLevel())
        pWindow->showMinimized();
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    if(real <= 90) {
        painter.setTransform(QTransform()
                             .translate(this->width() / 2, this->height() / 2)
                             .rotate(real - 360 * 1, Qt::YAxis)
                             .translate(-this->width() / 2, -this->height() / 2));
        painter.drawPixmap(ui->frame->pos().rx(),
                           ui->frame->pos().ry(),
                           //ui->frame->pos().rx() +
                           ui->frame->size().width(),
                           //ui->frame->pos().ry() +
                           ui->frame->size().height(),
                           currentMap);
    } else {
        painter.setTransform(QTransform()
                             .translate(this->width() / 2, this->height() / 2)
                             .rotate(180 * 1 + real, Qt::YAxis)
                             .translate(-this->width() / 2, -this->height() / 2));
        painter.drawPixmap(ui->frame->pos().rx(),
                           ui->frame->pos().ry(),
                           //ui->frame->pos().rx() +
                           ui->frame->size().width(),
                           //ui->frame->pos().ry() +
                           ui->frame->size().height(),
                           nextMap);
    }
}

void Widget::rotate()
{
    if(state == Clockwise) {
        if(real < 180) {
            this->update();
            real = real + 6;
        } else {
            timer->stop();
            real = 0;
            this->update();
            ui->frame_2->setVisible(true);
        }
    } else {
        if(real > 0) {
            this->update();
            real = real - 6;
        } else {
            timer->stop();
            real = 0;
            this->update();
            ui->frame->setVisible(true);
        }
    }
}


