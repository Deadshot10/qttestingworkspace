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

    Model  m_model = Model(context(),
                            {0.5, 0.5, -0.5, 0.5, -0.5, -0.5, 0.5, -0.5},
                            {1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0},
                            {0, 1, 2, 2, 3, 0});
    m_model.bindTexture();
    m_model.bindShaderProg();
    m_model.bindVertexArray();
    //glDrawArrays(GL_TRIANGLES, 0, 6);
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

}
