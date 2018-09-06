#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<iostream>
#include<string.h>
#include<conio.h>

#include "Graphics.h"

void RenderRoutine(Graphics* gfx);
int main()
{
	if (!glfwInit())
	{
		std::cout << "Failed To Initialize Glfw... Now Quitting" << std::endl;
		_getch();
		exit(-1);
	}

	Graphics gfx(1280, 1280, "Test");
	gfx.SetAsCurrentContext();

	if (glewInit())
	{
		std::cout << "Failed To Initialize Glew Now Quitting" << std::endl;
		_getch();
		exit(-1);
	}

	//Main Loop For The Window
	while (!gfx.ShouldWindowClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);


		glColor3f(255, 255, 255);

		//Render here
		RenderRoutine(&gfx);

		glfwSwapBuffers(gfx.GetWindowAssociated());
		glfwPollEvents();

	}

	glfwTerminate();
	return 0;
	
}

void RenderRoutine(Graphics*gfx)
{
	//Test Purposes Only
	gfx->DrawLine({ 0,0 }, { 1280,1280 }, { 255,255,255 });
}