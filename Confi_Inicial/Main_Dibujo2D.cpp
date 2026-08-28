//Practica #2
//Cruz Herrera Jocelyn Violeta
//Fecha de entrega: 27 de agosto del 2026
//No. cuenta: 320202238

#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;


int main() {
	glfwInit();
	//Verificaci�n de compatibilidad 
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Practica #2 Jocelyn Cruz", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, resize);
	
	//Verificaci�n de errores de creacion  ventana
	if (window== NULL) 
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificaci�n de errores de inicializaci�n de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Imprimimos informacin de OpenGL del sistema
	std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;


	// Define las dimensiones del viewport
	//glViewport(0, 0, screenWidth, screenHeight);

    Shader ourShader("Shader/core.vs", "Shader/core.frag");

	// Set up vertex data (and buffer(s)) and attribute pointers
	float vertices[] = {
		0.0f,  0.0f, 0.0f,    1.0f,5.0f,0.0f,  // naranja

		0.0f,  0.05f, 0.0f,    1.0f,0.5f,0.0f,  // naranja
		0.0f,  0.10f, 0.0f,    1.0f,1.0f,1.0f,  // blanco
		0.0f,  0.15f, 0.0f,    0.435f,0.306f,0.216f,  // cafe
		0.0f,  0.20f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro
		0.0f,  0.25f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro
		0.0f,  0.30f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro
		0.0f,  0.35f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro
		0.0f,  0.40f, 0.0f,    0.827f,0.827f,0.827f, // gris
		0.0f,  0.45f, 0.0f,    0.827f,0.827f,0.827f, // gris
		0.0f,  0.50f, 0.0f,    1.0f,1.0f,1.0f,  // blanco
		0.0f,  0.55f, 0.0f,    0.827f,0.827f,0.827f, // gris

		0.0f,  -0.05f, 0.0f,   0.8f,0.35f,0.0f,  // naranja fuerte
		0.0f,  -0.10f, 0.0f,   1.0f,0.5f,0.0f,  // naranja
		0.0f,  -0.15f, 0.0f,   0.435f,0.306f,0.216f,  // cafe
		0.0f,  -0.20f, 0.0f,   0.5f,0.8f,1.0f,  // azul claro
		0.0f,  -0.25f, 0.0f,   0.5f,0.8f,1.0f,  // azul claro
		0.0f,  -0.30f, 0.0f,   1.0f,0.77f,0.82f, // rosa
		0.0f,  -0.35f, 0.0f,   1.0f,0.77f,0.82f, // rosa
		0.0f,  -0.40f, 0.0f,   1.0f,0.0f,1.0f, // magenta
		0.0f,  -0.45f, 0.0f,   1.0f,0.0f,1.0f, // magenta
		0.0f,  -0.50f, 0.0f,   1.0f,1.0f,1.0f,  // blanco
		0.0f,  -0.55f, 0.0f,   0.827f,0.827f,0.827f, // gris

		0.05f,  0.0f, 0.0f,    1.0f,0.5f,0.0f,  // naranja

		0.05f,  0.05f, 0.0f,    1.0f,1.0f,1.0f,  // blanco
		0.05f,  0.10f, 0.0f,    1.0f,1.0f,1.0f,  // blanco
		0.05f,  0.15f, 0.0f,    0.435f,0.306f,0.216f,  // cafe
		0.05f,  0.20f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro
		0.05f,  0.25f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro
		0.05f,  0.30f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro
		0.05f,  0.35f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro
		0.05f,  0.40f, 0.0f,    0.827f,0.827f,0.827f, // gris
		0.05f,  0.45f, 0.0f,    0.827f,0.827f,0.827f, // gris
		0.05f,  0.50f, 0.0f,    1.0f,1.0f,1.0f,  // blanco
		0.05f,  0.55f, 0.0f,    0.827f,0.827f,0.827f, // gris

		0.05f,  -0.05f, 0.0f,   1.0f,1.0f,1.0f,  // blanco
		0.05f,  -0.10f, 0.0f,   1.0f,0.5f,0.0f,  // naranja
		0.05f,  -0.15f, 0.0f,   0.435f,0.306f,0.216f,  // cafe
		0.05f,  -0.20f, 0.0f,   0.5f,0.8f,1.0f,  // azul claro
		0.05f,  -0.25f, 0.0f,   0.5f,0.8f,1.0f,  // azul claro
		0.05f,  -0.30f, 0.0f,   0.5f,0.8f,1.0f,  // azul clar0
		0.05f,  -0.35f, 0.0f,   1.0f,0.77f,0.82f, // rosa
		0.05f,  -0.40f, 0.0f,   1.0f,0.77f,0.82f, // rosa
		0.05f,  -0.45f, 0.0f,   1.0f,0.0f,1.0f, // magenta
		0.05f,  -0.50f, 0.0f,   1.0f,1.0f,1.0f,  // blanco
		0.05f,  -0.55f, 0.0f,   0.827f,0.827f,0.827f, // gris

		0.10f,  0.0f, 0.0f,    1.0f,1.0f,1.0f,  // blanco

		0.10f,  0.05f, 0.0f,    1.0f,1.0f,1.0f,  // blanco
		0.10f,  0.10f, 0.0f,    1.0f,0.5f,0.0f,  // naranja
		0.10f,  0.15f, 0.0f,    0.435f,0.306f,0.216f,  // cafe
		0.10f,  0.20f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro
		0.10f,  0.25f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro
		0.10f,  0.30f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro
		0.10f,  0.35f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro
		0.10f,  0.40f, 0.0f,    0.827f,0.827f,0.827f, // gris
		0.10f,  0.45f, 0.0f,    0.827f,0.827f,0.827f, // gris
		0.10f,  0.50f, 0.0f,    1.0f,1.0f,1.0f,  // blanco
		0.10f,  0.55f, 0.0f,    0.827f,0.827f,0.827f, // gris

		0.10f,  -0.05f, 0.0f,   0.8f,0.35f,0.0f,  // naranja fuerte
		0.10f,  -0.10f, 0.0f,   0.435f,0.306f,0.216f,  // cafe
		0.10f,  -0.15f, 0.0f,   0.5f,0.8f,1.0f,  // azul claro
		0.10f,  -0.20f, 0.0f,   0.5f,0.8f,1.0f,  // azul claro
		0.10f,  -0.25f, 0.0f,   0.5f,0.8f,1.0f,  // azul claro
		0.10f,  -0.30f, 0.0f,   0.5f,0.8f,1.0f,  // azul clar0
		0.10f,  -0.35f, 0.0f,   0.0f, 1.0f, 0.0f, // verde
		0.10f,  -0.40f, 0.0f,   1.0f,0.77f,0.82f, // rosa
		0.10f,  -0.45f, 0.0f,   1.0f,0.0f,1.0f, // magenta
		0.10f,  -0.50f, 0.0f,   1.0f,1.0f,1.0f,  // blanco
		0.10f,  -0.55f, 0.0f,   0.827f,0.827f,0.827f, // gris

		0.15f,  0.0f, 0.0f,    1.0f,0.5f,0.0f,  // naranja

		0.15f,  0.05f, 0.0f,    1.0f,0.5f,0.0f,  // naranja
		0.15f,  0.10f, 0.0f,    0.435f,0.306f,0.216f,  // cafe
		0.15f,  0.15f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro
		0.15f,  0.20f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro
		0.15f,  0.25f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro
		0.15f,  0.30f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro
		0.15f,  0.35f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro
		0.15f,  0.40f, 0.0f,    0.827f,0.827f,0.827f, // gris
		0.15f,  0.45f, 0.0f,    0.827f,0.827f,0.827f, // gris
		0.15f,  0.50f, 0.0f,    1.0f,1.0f,1.0f,  // blanco
		0.15f,  0.55f, 0.0f,    0.827f,0.827f,0.827f, // gris

		0.15f,  -0.05f, 0.0f,   0.435f,0.306f,0.216f,  // cafe
		0.15f,  -0.10f, 0.0f,   0.5f,1.0f,0.5f,  // verde claro
		0.15f,  -0.15f, 0.0f,   0.5f,0.8f,1.0f,  // azul claro
		0.15f,  -0.20f, 0.0f,   0.5f,0.8f,1.0f,  // azul claro
		0.15f,  -0.25f, 0.0f,   0.5f,1.0f,0.5f,  // verde claro
		0.15f,  -0.30f, 0.0f,   0.5f,1.0f,0.5f,  // verde claro
		0.15f,  -0.35f, 0.0f,   0.0f, 1.0f, 0.0f, // verde fuerte
		0.15f,  -0.40f, 0.0f,   0.0f, 1.0f, 0.0f, // verde fuerte
		0.15f,  -0.45f, 0.0f,   1.0f, 0.77f, 0.82f, // rosa
		0.15f,  -0.50f, 0.0f,   1.0f,1.0f,1.0f,  // blanco
		0.15f,  -0.55f, 0.0f,   0.827f,0.827f,0.827f, // gris

		0.20f,  0.0f, 0.0f,    0.8f,0.35f,0.0f,  // naranja fuerte

		0.20f, 0.05f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.20f, 0.10f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.20f, 0.15f, 0.0f, 0.435f, 0.306f, 0.216f,  // cafe
		0.20f, 0.20f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.20f, 0.25f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.20f, 0.30f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.20f, 0.35f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.20f, 0.40f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		0.20f, 0.45f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		0.20f, 0.50f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.20f, 0.55f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		0.20f, -0.05f, 0.0f, 0.435f, 0.306f, 0.216f,  // cafe
		0.20f, -0.10f, 0.0f, 0.435f, 0.306f, 0.216f,  // cafe
		0.20f, -0.15f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.20f, -0.20f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.20f, -0.25f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.20f, -0.30f, 0.0f, 0.0f, 1.0f, 0.0f, // verde fuerte
		0.20f, -0.35f, 0.0f, 0.0f, 1.0f, 0.0f, // verde fuerte
		0.20f, -0.40f, 0.0f, 0.0f, 1.0f, 0.0f, // verde fuerte
		0.20f, -0.45f, 0.0f, 0.0f, 1.0f, 0.0f, // verde fuerte
		0.20f, -0.50f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.20f, -0.55f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		0.25f,  0.0f, 0.0f,    0.435f,0.306f,0.216f,  // cafe

		0.25f, 0.05f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.25f, 0.10f, 0.0f, 1.0f, 0.5f, 0.0f, // naranja
		0.25f, 0.15f, 0.0f, 0.435f, 0.306f, 0.216f,  // cafe
		0.25f, 0.20f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.25f, 0.25f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.25f, 0.30f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.25f, 0.35f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.25f, 0.40f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		0.25f, 0.45f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		0.25f, 0.50f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.25f, 0.55f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		0.25f, -0.05f, 0.0f, 1.0f, 0.5f, 0.0f, // naranja
		0.25f, -0.10f, 0.0f, 0.435f, 0.306f, 0.216f,  // cafe
		0.25f, -0.15f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.25f, -0.20f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.25f, -0.25f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.25f, -0.30f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.25f, -0.35f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.25f, -0.40f, 0.0f, 0.0f, 1.0f, 0.0f, // verde fuerte
		0.25f, -0.45f, 0.0f, 0.0f, 1.0f, 0.0f, // verde fuerte
		0.25f, -0.50f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.25f, -0.55f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		0.30f,  0.0f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro

		0.30f, 0.05f, 0.0f, 0.435f, 0.306f, 0.216f,  // cafe
		0.30f, 0.10f, 0.0f, 0.435f, 0.306f, 0.216f,  // cafe
		0.30f, 0.15f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.30f, 0.20f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.30f, 0.25f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.30f, 0.30f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.30f, 0.35f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.30f, 0.40f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		0.30f, 0.45f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.30f, 0.50f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		0.30f, 0.55f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		0.30f, -0.05f, 0.0f, 0.435f, 0.306f, 0.216f,  // cafe
		0.30f, -0.10f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.30f, -0.15f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.30f, -0.20f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.30f, -0.25f, 0.0f, 0.0f, 1.0f, 0.0f, // verde fuerte
		0.30f, -0.30f, 0.0f, 0.0f, 1.0f, 0.0f, // verde fuerte
		0.30f, -0.35f, 0.0f, 0.0f, 1.0f, 0.0f, // verde fuerte
		0.30f, -0.40f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.30f, -0.45f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.30f, -0.50f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		0.35f,  0.0f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro

		0.35f, 0.05f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.35f, 0.10f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.35f, 0.15f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.35f, 0.20f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.35f, 0.25f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.35f, 0.30f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.35f, 0.35f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.35f, 0.40f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.35f, 0.45f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.35f, 0.50f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		0.35f, -0.05f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.35f, -0.10f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.35f, -0.15f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.35f, -0.20f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.35f, -0.25f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.35f, -0.30f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.35f, -0.35f, 0.0f, 0.0f, 1.0f, 0.0f, // verde fuerte
		0.35f, -0.40f, 0.0f, 0.0f, 1.0f, 0.0f, // verde fuerte
		0.35f, -0.45f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.35f, -0.50f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		0.40f,  0.0f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro

		0.40f, 0.05f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.40f, 0.10f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.40f, 0.15f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.40f, 0.20f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.40f, 0.25f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.40f, 0.30f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.40f, 0.35f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.40f, 0.40f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.40f, 0.45f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		0.40f, -0.05f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.40f, -0.10f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.40f, -0.15f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.40f, -0.20f, 0.0f, 0.0f, 1.0f, 0.0f, // verde fuerte
		0.40f, -0.25f, 0.0f, 0.0f, 1.0f, 0.0f, // verde fuerte
		0.40f, -0.30f, 0.0f, 0.0f, 1.0f, 0.0f, // verde fuerte
		0.40f, -0.35f, 0.0f, 0.0f, 1.0f, 0.0f, // verde fuerte
		0.40f, -0.40f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.40f, -0.45f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		0.45f,  0.0f, 0.0f,    0.5f,1.0f,0.5f,  // verde claro

		0.45f, 0.05f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.45f, 0.10f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.45f, 0.15f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.45f, 0.20f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.45f, 0.25f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.45f, 0.30f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.45f, 0.35f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.45f, 0.40f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		0.45f, -0.05f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.45f, -0.10f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.45f, -0.15f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.45f, -0.20f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.45f, -0.25f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.45f, -0.30f, 0.0f, 0.0f, 1.0f, 0.0f, // verde fuerte
		0.45f, -0.35f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.45f, -0.40f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		0.50f,  0.0f, 0.0f,    0.5f,0.8f,1.0f,  // azul claro

		0.50f, 0.05f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.50f, 0.10f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.50f, 0.15f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.50f, 0.20f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.50f, 0.25f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.50f, 0.30f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		0.50f, 0.35f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		0.50f, -0.05f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.50f, -0.10f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		0.50f, -0.15f, 0.0f, 0.5f, 1.0f, 0.5f,  // verde claro
		0.50f, -0.20f, 0.0f, 0.0f, 1.0f, 0.0f, // verde fuerte
		0.50f, -0.25f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.50f, -0.30f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.50f, -0.35f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		0.55f,  0.0f, 0.0f,    1.0f,1.0f,1.0f, // blanco

		0.55f, 0.05f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.55f, 0.10f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.55f, 0.15f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.55f, 0.20f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.55f, 0.25f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		0.55f, 0.30f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		0.55f, -0.05f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.55f, -0.10f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.55f, -0.15f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.55f, -0.20f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		0.55f, -0.25f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		0.55f, -0.30f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		0.60f,  0.0f, 0.0f,    0.827f,0.827f,0.827f, // gris

		0.60f, 0.05f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		0.60f, 0.10f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		0.60f, 0.15f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		0.60f, 0.20f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		0.60f, -0.05f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		0.60f, -0.10f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		0.60f, -0.15f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		0.60f, -0.20f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.05f,  0.0f, 0.0f,   0.0f,0.0f,0.0f, // negro 

		-0.05f, 0.05f, 0.0f, 1.0f, 0.5f, 0.0f,  // naranja
		-0.05f, 0.10f, 0.0f, 1.0f, 0.5f, 0.0f,  // naranja
		-0.05f, 0.15f, 0.0f, 0.435f, 0.306f, 0.216f,  // cafe
		-0.05f, 0.20f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.05f, 0.25f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.05f, 0.30f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.05f, 0.35f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.05f, 0.40f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.05f, 0.45f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.05f, 0.50f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.05f, 0.55f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.05f, -0.05f, 0.0f, 0.8f, 0.35f, 0.0f,  // naranja fuerte
		-0.05f, -0.10f, 0.0f, 0.435f, 0.306f, 0.216f,  // cafe
		-0.05f, -0.15f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.05f, -0.20f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.05f, -0.25f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.05f, -0.30f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul clar0
		-0.05f, -0.35f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.05f, -0.40f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.05f, -0.45f, 0.0f, 1.0f, 0.0f, 1.0f, // magenta
		-0.05f, -0.50f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.05f, -0.55f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.10f,  0.0f, 0.0f,   1.0f,0.5f,0.0f, // naranja

		-0.10f, 0.05f, 0.0f, 1.0f, 0.5f, 0.0f,  // naranja
		-0.10f, 0.10f, 0.0f, 0.435f, 0.306f, 0.216f,  // cafe
		-0.10f, 0.15f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.10f, 0.20f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.10f, 0.25f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.10f, 0.30f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.10f, 0.35f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.10f, 0.40f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.10f, 0.45f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.10f, 0.50f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.10f, 0.55f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.10f, -0.05f, 0.0f, 0.8f, 0.35f, 0.0f,  // naranja fuerte
		-0.10f, -0.10f, 0.0f, 0.435f, 0.306f, 0.216f,  // cafe
		-0.10f, -0.15f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.10f, -0.20f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.10f, -0.25f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.10f, -0.30f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.10f, -0.35f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.10f, -0.40f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.10f, -0.45f, 0.0f, 1.0f, 0.0f, 1.0f, // magenta
		-0.10f, -0.50f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.10f, -0.55f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.15f,  0.0f, 0.0f,   1.0f,0.5f,0.0f, // naranja

		-0.15f, 0.05f, 0.0f, 0.435f, 0.306f, 0.216f,  // cafe
		-0.15f, 0.10f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.15f, 0.15f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.15f, 0.20f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.15f, 0.25f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.15f, 0.30f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.15f, 0.35f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.15f, 0.40f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.15f, 0.45f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.15f, 0.50f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.15f, 0.55f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.15f, -0.05f, 0.0f, 0.8f, 0.35f, 0.0f,  // naranja fuerte
		-0.15f, -0.10f, 0.0f, 0.435f, 0.306f, 0.216f,  // cafe
		-0.15f, -0.15f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.15f, -0.20f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.15f, -0.25f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.15f, -0.30f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.15f, -0.35f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.15f, -0.40f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.15f, -0.45f, 0.0f, 1.0f, 0.0f, 1.0f, // magenta
		-0.15f, -0.50f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.15f, -0.55f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.20f,  0.0f, 0.0f,   0.435f, 0.306f, 0.216f, // cafe

		-0.20f, 0.05f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.20f, 0.10f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.20f, 0.15f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.20f, 0.20f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.20f, 0.25f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.20f, 0.30f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.20f, 0.35f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.20f, 0.40f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.20f, 0.45f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.20f, 0.50f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.20f, 0.55f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.20f, -0.05f, 0.0f, 0.435f, 0.306f, 0.216f,  // cafe
		-0.20f, -0.10f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.20f, -0.15f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.20f, -0.20f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.20f, -0.25f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.20f, -0.30f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.20f, -0.35f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.20f, -0.40f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.20f, -0.45f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.20f, -0.50f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.20f, -0.55f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.25f,  0.0f, 0.0f,   1.0f,0.77f,0.82f, // rosa

		-0.25f, 0.05f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.25f, 0.10f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.25f, 0.15f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.25f, 0.20f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.25f, 0.25f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.25f, 0.30f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.25f, 0.35f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.25f, 0.40f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.25f, 0.45f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.25f, 0.50f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.25f, 0.55f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.25f, -0.05f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.25f, -0.10f, 0.0f, 1.0f, 0.0f, 1.0f, // magenta
		-0.25f, -0.15f, 0.0f, 1.0f, 0.0f, 1.0f, // magenta
		-0.25f, -0.20f, 0.0f, 1.0f, 0.0f, 1.0f, // magenta
		-0.25f, -0.25f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.25f, -0.30f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.25f, -0.35f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.25f, -0.40f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.25f, -0.45f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.25f, -0.50f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.30f,  0.0f, 0.0f,   1.0f,0.0f,1.0f, // magenta

		-0.30f, 0.05f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.30f, 0.10f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.30f, 0.15f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.30f, 0.20f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.30f, 0.25f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.30f, 0.30f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.30f, 0.35f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.30f, 0.40f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.30f, 0.45f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.30f, 0.50f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.30f, -0.05f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.30f, -0.10f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.30f, -0.15f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.30f, -0.20f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.30f, -0.25f, 0.0f, 1.0f, 0.0f, 1.0f, // magenta
		-0.30f, -0.30f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.30f, -0.35f, 0.0f, 1.0f, 0.0f, 1.0f, // magenta
		-0.30f, -0.40f, 0.0f, 1.0f, 0.0f, 1.0f, // magenta
		-0.30f, -0.45f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.30f, -0.50f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.35f,  0.0f, 0.0f,   0.5f, 0.8f, 1.0f, // azul claro

		-0.35f, 0.05f, 0.0f, 0.5f, 0.8f, 1.0f, // azul claro
		-0.35f, 0.10f, 0.0f, 0.5f, 0.8f, 1.0f, // azul claro
		-0.35f, 0.15f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.35f, 0.20f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.35f, 0.25f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.35f, 0.30f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.35f, 0.35f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.35f, 0.40f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.35f, 0.45f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.35f, -0.05f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.35f, -0.10f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.35f, -0.15f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.35f, -0.20f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.35f, -0.25f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.35f, -0.30f, 0.0f, 1.0f, 0.0f, 1.0f, // magenta
		-0.35f, -0.35f, 0.0f, 1.0f, 0.0f, 1.0f, // magenta
		-0.35f, -0.40f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.35f, -0.45f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.40f,  0.0f, 0.0f,   0.5f, 0.8f, 1.0f, // azul claro

		-0.40f, 0.05f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.40f, 0.10f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.40f, 0.15f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.40f, 0.20f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.40f, 0.25f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.40f, 0.30f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.40f, 0.35f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.40f, 0.40f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.40f, -0.05f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.40f, -0.10f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.40f, -0.15f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.40f, -0.20f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.40f, -0.25f, 0.0f, 1.0f, 0.0f, 1.0f, // magenta
		-0.40f, -0.30f, 0.0f, 1.0f, 0.0f, 1.0f, // magenta
		-0.40f, -0.35f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.40f, -0.40f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.45f,  0.0f, 0.0f,   1.0f,0.77f,0.82f, // rosa

		-0.45f, 0.05f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.45f, 0.10f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.45f, 0.15f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.45f, 0.20f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.45f, 0.25f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.45f, 0.30f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.45f, 0.35f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.45f, -0.05f, 0.0f, 1.0f, 0.77f, 0.82f, // rosa
		-0.45f, -0.10f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.45f, -0.15f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.45f, -0.20f, 0.0f, 0.5f, 0.8f, 1.0f,  // azul claro
		-0.45f, -0.25f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.45f, -0.30f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.45f, -0.35f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.50f,  0.0f, 0.0f,   1.0f,1.0f,1.0f, // blanco

		-0.50f, 0.05f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.50f, 0.10f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.50f, 0.15f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.50f, 0.20f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.50f, 0.25f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.50f, 0.30f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.50f, -0.05f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.50f, -0.10f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.50f, -0.15f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.50f, -0.20f, 0.0f, 1.0f, 1.0f, 1.0f,  // blanco
		-0.50f, -0.25f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.50f, -0.30f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.55f,  0.0f, 0.0f,   0.827f,0.827f,0.827f, // gris
		
		-0.55f, 0.05f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.55f, 0.10f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.55f, 0.15f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.55f, 0.20f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

		-0.55f, -0.05f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.55f, -0.10f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.55f, -0.15f, 0.0f, 0.827f, 0.827f, 0.827f, // gris
		-0.55f, -0.20f, 0.0f, 0.827f, 0.827f, 0.827f, // gris

	};
	unsigned int indices[] = {  // note that we start from 0!
		3,2,1,// second Triangle
		0,1,3,
		
	};



	GLuint VBO, VAO,EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)


	
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Draw our first triangle
        ourShader.Use();
        glBindVertexArray(VAO);


        glPointSize(13);
        glDrawArrays(GL_POINTS,0,580);
        
        //glDrawArrays(GL_LINES,4,2);
        //glDrawArrays(GL_LINE_LOOP,0,4);
        
        //glDrawArrays(GL_TRIANGLES,0,3);
        //glDrawElements(GL_TRIANGLES, 3,GL_UNSIGNED_INT,0);

        
        
        glBindVertexArray(0);
    
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}



	glfwTerminate();
	return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the size of the created window
	glViewport(0, 0, width, height);
	//glViewport(0, 0, screenWidth, screenHeight);
}