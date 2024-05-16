#version 330 core

out vec4 FragColor;

in vec3 oColor;
in vec2 oTexCoord;

uniform bool useTexture;
uniform sampler2D SpriteTexture;

void main()
{
    if(useTexture == true)
        FragColor =  texture(SpriteTexture, oTexCoord) * vec4(oColor, 1);
    else
        FragColor = vec4(oColor, 1);
}