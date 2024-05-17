#include "Window.h"
#include "Renderer.h"
#include "Sprite.h"

int main(void)
{
    Window window = Window(1080, 720, "2D Renderer");
    Renderer* renderer = new Renderer(&window);
    renderer->setBackgroundColor(1.0f, 1.0f, 1.0f);

    Sprite sprite = Sprite("res/sprites/player.png");
    Sprite TreeSprite = Sprite("res/sprites/tree.jpg");

    double prevTime = glfwGetTime();
    int frameCount = 0;

    while (window.isOpen())
    {
        double currentTime = glfwGetTime();
        frameCount++;
        if (currentTime - prevTime >= 1.0)
        {
            std::cout << "FRAME RATE: " << frameCount << "\n";
            frameCount = 0;
            prevTime = currentTime;
        }

        renderer->clear();
        
        renderer->drawRect(window.WindowWidth / 2, window.WindowHeight / 2, 200, 200, 255, 0, 0.0);

        renderer->drawSprite(sprite, 0, 500, 0.15f);
        renderer->drawSprite(TreeSprite, 500, 500, 1);


        window.update();

        if (window.isKeyPressed(GLFW_KEY_ESCAPE))
            window.close();
    }
    delete(renderer);
    window.terminate();
    return 0;
}