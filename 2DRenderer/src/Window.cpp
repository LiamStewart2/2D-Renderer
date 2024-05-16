#include "Window.h"

#include <iostream>

Window::Window(int window_width, int window_height, const char* window_name): WindowWidth(window_width), WindowHeight(window_height), WindowName(window_name)
{
    if (!glfwInit())
        std::cout << "GLFW INIT FAILED" << std::endl;

    else

    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(window_width, window_height, window_name, NULL, NULL);
        if (!window)
        {
            std::cout << "GLFW Window init failed" << std::endl;
            terminate();
        }
        else
        {
            glfwMakeContextCurrent(window);
            glfwSwapInterval(0);

            GLenum err = glewInit();
            if (err != GLEW_OK)
            {
                fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
                terminate();
            }
        }
    }
}

void Window::update()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::close()
{
    glfwSetWindowShouldClose(window, true);
}
void Window::terminate()
{
    glfwTerminate();
}

bool Window::isKeyPressed(int key)
{
    int state = glfwGetKey(window, key);
    if (state == GLFW_PRESS)
        return true;
}