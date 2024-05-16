#pragma once
class Texture
{
public:
	Texture(const char* imagePath);
	Texture() {}
	~Texture() {}

	void useTexture();
	unsigned int textureID;
	int width, height, nrChannels;
};