#ifndef WIDGET_H
#define WIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMouseEvent>
#include <QDebug>
#include <QGuiApplication> //for keyboard modifers
#include <QDateTime>
#include <QBasicTimer>
#include <QElapsedTimer>
#include <QPainter>

#include "model.h"


class Widget  : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:

protected:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void timerEvent(QTimerEvent *e) override;

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void showFPS();
    qint64 checkTime;
    int frames;
    int framesDisplayed;
    QBasicTimer timer;
    QElapsedTimer timerE;
    //QPoint pressPosition;
    //QPoint releasePosition;
    GLfloat currentWidth;
    GLfloat currentHeight;

};

#endif // WIDGET_H
