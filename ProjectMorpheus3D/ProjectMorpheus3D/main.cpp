#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<iostream>
#include<string.h>
#include<conio.h>

#include "Graphics.h"
#include "Keyboard.h"
#include "Game.h"

//Global Keyboard Object.. //As The Engine Supports Only One Keyboard...
Keyboard keyboard;

void RenderRoutine(Graphics* gfx);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
int main()
{
	if (!glfwInit())
	{
		std::cout << "Failed To Initialize Glfw... Now Quitting" << std::endl;
		_getch();
		exit(-1);
	}

	//Creating Graphics Object..
	Graphics gfx(1280, 1280, "Test");
	gfx.SetAsCurrentContext();

	//Creating A Game Object
	Game gme("MainGame", gfx,&keyboard);

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
		if (!gme.IsGameOver()) //Game Not Over...
		{
			gme.GameLoop();
		}
		//RenderRoutine(&gfx);

		glfwSwapBuffers(gfx.GetWindowAssociated());
		glfwPollEvents();
		glfwSetKeyCallback(gfx.GetWindowAssociated(), key_callback); //As there is only one window otherwise modify this statement to include all windows
	}

	glfwTerminate();
	return 0;
	
}

void RenderRoutine(Graphics*gfx)
{
	//Test Purposes Only
	gfx->DrawLine({ 0,0 }, { 1280,1280 }, { 255,255,255 });
}

//Sets Key Flags Depending on Which Key Is Pressed
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	keyboard.keys[key] = true;
	std::cout << key << std::endl;
}