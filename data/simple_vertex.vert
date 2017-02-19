#version 330

layout (location = 0) in vec2 inVertexPositin;
layout (location = 1) in vec2 inTexturePosition;

out vec2 passTexturePos;

void main (void)
{
    gl_Position = vec4 (inVertexPositin.x, inVertexPositin.y, 0.0, 1.0);
    passTexturePos = inTexturePosition;
}
