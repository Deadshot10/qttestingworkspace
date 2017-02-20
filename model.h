#ifndef MODEL_H
#define MODEL_H

#include <QOpenGLFunctions>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

class Model : protected QOpenGLFunctions
{
public:
    Model(QOpenGLContext* context,
          const std::vector<GLfloat>& vertexPositions,
          const std::vector<GLfloat>& texturePositions,
          const std::vector<GLuint>& indices);
    ~Model();
    void bindVertexArray();
    void unbindVertexArray();
    void bindShaderProg();
    void unbindShaderProg();
    void bindTexture();
    void unbindTexture();
    GLuint getIndicesCount() const;
private:
    void addVBO(int dim, const std::vector<GLfloat>& data);
    void addEBO(const std::vector<GLuint> &indices);
    GLuint m_vboCount = 0;
    GLuint m_indicesCount = 0;
    std::vector<QOpenGLBuffer> m_buffers;
    QOpenGLVertexArrayObject* m_vao;
    QOpenGLShader* m_vertShader;
    QOpenGLShader* m_fragShader;
    QOpenGLShaderProgram* m_shaderProg;
    QOpenGLTexture *m_texture;

};

#endif // MODEL_H
