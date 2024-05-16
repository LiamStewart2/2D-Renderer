#include "Renderer.h"

Renderer::Renderer(Window* _window)
{
	window = _window;

	shader = Shader("src/Shaders/Default/shader.vs", "src/Shaders/Default/shader.fs");
	
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(RectVertices), RectVertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

Renderer::~Renderer()
{

}

void Renderer::clear()
{
	glClearColor(backgroundColorR, backgroundColorG, backgroundColorB, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::setBackgroundColor(float r, float g, float b)
{
	backgroundColorR = r; backgroundColorG = g; backgroundColorB = b;
}


void Renderer::drawRect(float x, float y, float w, float h, float r, float g, float b)
{
	shader.useShader();

	// TOP RIGHT
	RectVertices[0] = x + w;	RectVertices[1] = y;		RectVertices[2] = r;	RectVertices[3] = g;	RectVertices[4] = b;	RectVertices[5] = 1;	RectVertices[6] = 1;
	// BOTTOM RIGHT
	RectVertices[7] = x + w;	RectVertices[8] = y - h;	RectVertices[9] = r;	RectVertices[10] = g;	RectVertices[11] = b;	RectVertices[12] = 1;	RectVertices[13] = 0;
	// BOTTOM LEFT
	RectVertices[14] = x;		RectVertices[15] = y - h;	RectVertices[16] = r;	RectVertices[17] = g;	RectVertices[18] = b;	RectVertices[19] = 0;	RectVertices[20] = 0;
	// TOP LEFT
	RectVertices[21] = x;		RectVertices[22] = y;		RectVertices[23] = r;	RectVertices[24] = g;	RectVertices[25] = b;	RectVertices[26] = 0;	RectVertices[27] = 1;

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(RectVertices), RectVertices, GL_STATIC_DRAW);

	shader.setBool("useTexture", false);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer::drawSprite(Sprite sprite, float x, float y, float scale)
{
	shader.useShader();

	float w = sprite.texture.width * scale;
	float h = sprite.texture.height * scale;

	float r = 1; float g = 1; float b = 1;

	// TOP RIGHT
	RectVertices[0] = x + w;	RectVertices[1] = y;		RectVertices[2] = r;	RectVertices[3] = g;	RectVertices[4] = b;	RectVertices[5] = 1;	RectVertices[6] = 1;
	// BOTTOM RIGHT
	RectVertices[7] = x + w;	RectVertices[8] = y - h;	RectVertices[9] = r;	RectVertices[10] = g;	RectVertices[11] = b;	RectVertices[12] = 1;	RectVertices[13] = 0;
	// BOTTOM LEFT
	RectVertices[14] = x;		RectVertices[15] = y - h;	RectVertices[16] = r;	RectVertices[17] = g;	RectVertices[18] = b;	RectVertices[19] = 0;	RectVertices[20] = 0;
	// TOP LEFT
	RectVertices[21] = x;		RectVertices[22] = y;		RectVertices[23] = r;	RectVertices[24] = g;	RectVertices[25] = b;	RectVertices[26] = 0;	RectVertices[27] = 1;

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(RectVertices), RectVertices, GL_STATIC_DRAW);

	sprite.texture.useTexture();
	shader.setBool("useTexture", true);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer::EnableDebug()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}