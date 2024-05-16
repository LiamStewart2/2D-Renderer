#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Renderer.h"

int main(void)
{
    Window window = Window(1080, 720, "2D Renderer");
    Renderer* renderer = new Renderer();
    
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

        window.update();

        if (window.isKeyPressed(GLFW_KEY_ESCAPE))
            window.close();
    }
    delete(renderer);
    window.terminate();
    return 0;
}