#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 oColor;
out vec2 oTexCoord;

void main()
{
	gl_Position = vec4(aPos.x, aPos.y, 1, 1);
	oTexCoord = aTexCoord;
	oColor = aColor;
}