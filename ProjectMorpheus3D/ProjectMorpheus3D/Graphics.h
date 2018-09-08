#pragma once
#include<gl/glew.h>
#include<GLFW/glfw3.h>

#include<iostream>
#include<string>
#include<vector>

#include "Color.h"
#include "Vec2.h"

class Graphics
{
public:
	Graphics() = delete;
	Graphics(int WindowWidth,int WindowHeight,std::string WindowName)
		:
		Width(WindowWidth),
		Height(WindowHeight),
		WindowName(WindowName),
		CurrentWindow(glfwCreateWindow(WindowWidth,WindowHeight,WindowName.c_str(),NULL,NULL))
	{
		if (!CurrentWindow)
		{
			std::cout << WindowName << " Window failed to initialize!! Shutting Down OpenGl And Exitting Program....." << std::endl;
			glfwTerminate();
			ShutDownWindow = true;
		}
	}
private:
	GLFWwindow* CurrentWindow;
	int Width;
	int Height;
	std::string WindowName;

	//Flags
	bool ShutDownWindow = false;

public:
	//Helper Functions
	GLFWwindow * GetWindowAssociated();
	bool ShouldWindowClose();
	void SetAsCurrentContext();
	int GetScreenHeight();
	int GetScreenWidth();

	//MainFunctions
public:
	/*
	IMPORTANT------
		Note- In PutPixel Y Goes from 1 to Height Whereas 
						  X Goes from 0 to Height-1
	*/
	void PutPixel(int Width,int Height,Color c);
	void DrawLine(const Vec2& p1, const Vec2& p2, Color c)
	{
		DrawLine(p1.x, p1.y, p2.x, p2.y, c);
	}
	
	//Private Functions
private:
	void DrawLine(float x1, float y1, float x2, float y2, Color c);
	void GetNormalized(Vec2& ScreenCoordinates);
};