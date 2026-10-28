// TON618.cpp: Uygulamanın giriş noktasını tanımlar.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "TON618.h"

using namespace std;

int main()
{
	if (!glfwInit()) {
		std::cerr << "Failed to initalize GLFW!\n";
		return -1;
	}
	std::cout << "GLFW initialized successfully!\n";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(
	1000,
	800,
	"TON618 Simulation",
	nullptr,
	nullptr
	);
	if (window == nullptr) {
		std::cerr << "Failed to create GLFW window";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initialize GLAD";
		glfwDestroyWindow(window);
		glfwTerminate();
		return -1;
	}
	std::cout << "Window created successfully!\n";
	std::cout << "GLAD initialized successfully!\n";

	float vertices[] = {
		-0.5, -0.5, 0.0,
		0.5, -0.5, 0.0,
		0.0, 0.5, 0.0
	};

	unsigned int VBO;
	glGenBuffers(1, &VBO);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteBuffers(1, &VBO);
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
