#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
    {
        std::cout << "GLFW INIT FAILED" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1080, 720, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
        return -1;
    }

    Renderer* renderer = new Renderer();
    //renderer->EnableDebug();

    glfwSwapInterval(0);
    
    float x = -1.0f;
    float r = 1.0f;
    float dir = -0.001f;

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        renderer->drawRect(x, -0.2f, 0.4f, 0.5f, r, x, 0.0);
        x += 0.00001f;
        r += dir;
        if (r <= 0.0f || r >= 1.0f)
            dir *= -1;

        glfwSwapBuffers(window);

        glfwPollEvents();

        int state = glfwGetKey(window, GLFW_KEY_ESCAPE);
        if (state == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

    delete(renderer);
    glfwTerminate();
    return 0;
}