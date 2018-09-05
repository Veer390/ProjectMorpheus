#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<iostream>
#include<string.h>
#include<conio.h>

int main()
{
	if (!glfwInit())
	{
		std::cout << "Failed To Initialize Glfw... Now Quitting" << std::endl;
		_getch();
		exit(-1);
	}

	while (true);
	
}