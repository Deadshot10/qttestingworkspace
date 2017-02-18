#version 330

layout (location = 0) in vec2 inVertexPositin;

void main (void)
{
    gl_Position = vec4 (inVertexPositin.x, inVertexPositin.y, 0.0, 1.0);

}
