#include "Sprite.h"

Sprite::Sprite(const char* spriteImagePath)
{
	texture = Texture(spriteImagePath);
}