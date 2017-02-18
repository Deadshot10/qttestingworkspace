#ifndef MODEL_H
#define MODEL_H

#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>

class Model : protected QOpenGLFunctions
{
public:
    Model(QOpenGLContext* context, const std::vector<GLfloat>& vertexPositions);
    ~Model();
    void bind();
    void unbind();
private:
    void addVBO(int dim, const std::vector<GLfloat>& data);
    GLuint m_vboCount = 0;
    std::vector<QOpenGLBuffer> m_buffers;
    QOpenGLVertexArrayObject* m_vao;

};

#endif // MODEL_H
