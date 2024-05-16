#pragma once

#include "Window.h"
#include "Shader.h"
#include "Sprite.h"
#include "Texture.h"

class Renderer
{
public:
	Renderer(Window* _window);
	Renderer() {}
	~Renderer();

	void EnableDebug();
	
	void clear();
	void drawRect(float x, float y, float w, float h, float r, float g, float b);
	void drawSprite(Sprite sprite, float x, float y, float scale);

	void setBackgroundColor(float r, float g, float b);
private:
	Window* window;

	Shader shader;
	Texture RectTexture;

	float backgroundColorR = 1.0f;
	float backgroundColorG = 1.0f;
	float backgroundColorB = 1.0f;

	float RectVertices[4 * (2 + 3 + 2)];

	unsigned int indices[6] = {
		0, 1, 3,
		1, 2, 3
	};

	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;
};

