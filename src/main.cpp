#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int g_windowSizeX = 1024;
int g_windowSizeY = 800;

void glfwWindowSizeCallback(GLFWwindow* pwindow, int width, int height)
{
    g_windowSizeX = width;
    g_windowSizeY = height;
    glViewport(0, 0, g_windowSizeX, g_windowSizeY);
};

void glfwKeyCallback(GLFWwindow* pwindow, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(pwindow, GL_TRUE);
    }
};

int main(void)
{
 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    GLFWwindow* pwindow;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    pwindow = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "GameOpenGL", NULL, NULL);
    if (!pwindow)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(pwindow, glfwWindowSizeCallback);
    glfwSetKeyCallback(pwindow, glfwKeyCallback);
    /* Make the window's context current */
    glfwMakeContextCurrent(pwindow);

    if (!gladLoadGL())
	{
		std::cout<<"Can't load GLAD!"<<std::endl;
		return -1;
	}
    std::cout << "Renderer :" <<glGetString(GL_RENDERER)<< std::endl;
    std::cout << "OpenGL version :" <<glGetString(GL_VERSION)<< std::endl;

	
	

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pwindow))
    {
        /* Render here */
        glClearColor(0, 0, 0, 1);

        glClear(GL_COLOR_BUFFER_BIT);
        /* Swap front and back buffers */
        glfwSwapBuffers(pwindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}