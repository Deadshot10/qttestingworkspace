#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{

}

Widget::~Widget()
{

}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();
    timer.start(0, this);
    timerE.start();
    checkTime = frames = framesDisplayed = 0;
}

void Widget::resizeGL(int w, int h)
{
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
//    glViewport(0, 0, (GLint)w, (GLint)h);

    currentWidth = w;
    currentHeight = h;
}

void Widget::paintGL()
{
    glClearColor(0.77, 0.77, 0.77, 1.0);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    showFPS();

    Model  m_model = Model(context(),
                            {0.5, 0.5, -0.5, 0.5, -0.5, -0.5, 0.5, -0.5},
                            {1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0},
                            {0, 1, 2, 2, 3, 0});

    m_model.bindTexture();
    m_model.bindShaderProg();
    m_model.bindVertexArray();
    m_model.setTime(timerE.elapsed()/1000.0);
    glDrawElements(GL_TRIANGLES, m_model.getIndicesCount(), GL_UNSIGNED_INT, 0);
    m_model.unbindVertexArray();
    m_model.unbindShaderProg();
    m_model.unbindTexture();



}

void Widget::mousePressEvent(QMouseEvent *e)
{
    if (QGuiApplication::keyboardModifiers() == Qt::ShiftModifier){
        if (isFullScreen())
            showNormal();
        else
            showFullScreen();
    }
    if (QGuiApplication::keyboardModifiers() == Qt::ControlModifier){

    }

}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{


}

void Widget::mouseMoveEvent(QMouseEvent *e)
{

}

void Widget::timerEvent(QTimerEvent *e)
{
    update();
}

void Widget::showFPS(){
    frames++;
    qint64 currentTime = QDateTime::currentMSecsSinceEpoch();
    if (currentTime - checkTime >= 1000)
    {
        framesDisplayed = frames;
        frames = 0;
        checkTime = currentTime;
    }
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 16));
    painter.drawText(0, 0, 70, 20, Qt::AlignCenter, "FPS:" + QString::number(framesDisplayed));
    painter.end();
}
