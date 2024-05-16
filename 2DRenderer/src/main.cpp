#include "Window.h"
#include "Renderer.h"
#include "Sprite.h"

int main(void)
{
    Window window = Window(800, 800, "2D Renderer");
    Renderer* renderer = new Renderer(&window);
    renderer->setBackgroundColor(1.0f, 1.0f, 1.0f);
   

    Sprite sprite = Sprite("res/sprites/player.png");

    float x = -1.0f;
    float r = 1.0f;
    float dir = -0.001f;

    while (window.isOpen())
    {
        renderer->clear();
        renderer->drawRect(x, -0.2f, 0.4f, 0.5f, r, x, 0.0);
        x += 0.00001f;
        r += dir;
        if (r <= 0.0f || r >= 1.0f)
            dir *= -1;

        renderer->drawSprite(sprite, -0.8f, 0.2f, 0.0004f);
        renderer->drawSprite(sprite, 0.8f, 0.2f, 0.0004f);
        renderer->drawSprite(sprite, -0.8f, -0.4f, 0.0004f);

        window.update();

        if (window.isKeyPressed(GLFW_KEY_ESCAPE))
            window.close();
    }
    delete(renderer);
    window.terminate();
    return 0;
}