#pragma once

#include "Shader.h"
#include "Sprite.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	void EnableDebug();
	
	void clear();
	void drawRect(float x, float y, float w, float h, float r, float g, float b);
	void drawSprite(Sprite sprite, float x, float y, float w, float h);
private:
	Shader shader;
	float RectVertices[4 * (2 + 3)];

	unsigned int indices[6] = {
		0, 1, 3,
		1, 2, 3
	};

	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;
};

