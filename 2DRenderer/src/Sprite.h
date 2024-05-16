#pragma once

#include "Texture.h"

class Sprite
{
public:
	Sprite(const char* spriteImagePath);
	Sprite() {}
	~Sprite() {}

	Texture texture;
private:

};

