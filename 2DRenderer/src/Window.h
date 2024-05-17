#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	Window(int window_width, int window_height, const char* window_name);
	~Window() { glfwTerminate(); }

	void update();
	void close();
	void terminate();

	bool isOpen() { return !glfwWindowShouldClose(window); }
	GLFWwindow* getGLFWwindow() { return window; }

	// Uses GLFW Key codes
	bool isKeyPressed(int key);
	int WindowWidth; int WindowHeight;
private:
	GLFWwindow* window;

	const char* WindowName;
};