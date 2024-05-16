#include "Renderer.h"

Renderer::Renderer()
{
	shader = Shader("shader.vs", "shader.fs");
	
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(RectVertices), RectVertices, GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

Renderer::~Renderer()
{

}

void Renderer::drawRect(float x, float y, float w, float h, float r, float g, float b)
{
	shader.useShader();

	RectVertices[0] = x + w;	RectVertices[1] = y;		RectVertices[2] = r;	RectVertices[3] = g;	RectVertices[4] = b;
	RectVertices[5] = x + w;	RectVertices[6] = y - h;	RectVertices[7] = r;	RectVertices[8] = g;	RectVertices[9] = b;
	RectVertices[10] = x;		RectVertices[11] = y - h;	RectVertices[12] = r;	RectVertices[13] = g;	RectVertices[14] = b;
	RectVertices[15] = x;		RectVertices[16] = y;		RectVertices[17] = r;	RectVertices[18] = g;	RectVertices[19] = b;

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(RectVertices), RectVertices, GL_STATIC_DRAW);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer::EnableDebug()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}