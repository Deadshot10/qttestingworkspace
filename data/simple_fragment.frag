#version 330

out vec4 color;
in vec2 passTexturePos;
uniform sampler2D outTexture;

uniform float time;

void main (void)
{
    //color = vec4(1.0, 0.0, 0.0, 1.0);
    color = texture2D(outTexture, passTexturePos) * sin(time);

}
