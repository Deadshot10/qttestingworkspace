#include "model.h"

#include <QDebug>

Model::Model(QOpenGLContext* context,
             const std::vector<GLfloat> &vertexPositions,
             const std::vector<GLfloat> &texturePositions)
    :
    QOpenGLFunctions(context)
{
    initializeOpenGLFunctions();

    m_texture = new QOpenGLTexture(QImage(":/data/grass.png").mirrored());
    m_texture->setMinificationFilter(QOpenGLTexture::Nearest);
    m_texture->setMagnificationFilter(QOpenGLTexture::Nearest);
    m_texture->setWrapMode(QOpenGLTexture::Repeat);

    m_vertShader = new QOpenGLShader(QOpenGLShader::Vertex, context);
    m_vertShader->compileSourceFile(":/data/simple_vertex.vert");

    m_fragShader = new QOpenGLShader(QOpenGLShader::Fragment, context);
    m_fragShader->compileSourceFile(":/data/simple_fragment.frag");

    m_shaderProg = new QOpenGLShaderProgram(context);
    m_shaderProg->addShader(m_vertShader);
    m_shaderProg->addShader(m_fragShader);
    m_shaderProg->link();

    m_vao = new QOpenGLVertexArrayObject(context);
    m_vao->create();

    m_vao->bind();
    addVBO(2, vertexPositions);
    addVBO(2, texturePositions);
    m_vao->release();


}

Model::~Model()
{
    m_buffers.clear(); // <- this is work correctly?
    m_vao->destroy();  // <- and this
}

void Model::bindVertexArray()
{
    m_vao->bind();

}

void Model::unbindVertexArray()
{
    m_vao->release();
}

void Model::bindShaderProg()
{
    m_shaderProg->bind();

}

void Model::unbindShaderProg()
{
    m_shaderProg->release();

}

void Model::bindTexture()
{
    m_texture->bind();

}

void Model::unbindTexture()
{
    m_texture->release();
}

void Model::addVBO(int dim, const std::vector<GLfloat> &data)
{
    QOpenGLBuffer m_vbo(QOpenGLBuffer::VertexBuffer);
    m_vbo.create();
    m_vbo.bind();
    m_vbo.allocate(data.data(), data.size() * sizeof(data[0]));
    glVertexAttribPointer(m_vboCount, dim, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
    glEnableVertexAttribArray(m_vboCount++);
    m_buffers.push_back(m_vbo);
    m_vbo.release();

}

