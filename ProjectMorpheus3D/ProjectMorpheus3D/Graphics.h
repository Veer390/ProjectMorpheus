#pragma once
#include<gl/glew.h>
#include<GLFW/glfw3.h>

#include<iostream>
#include<string>
#include<vector>

#include "Color.h"
#include "Vec2.h"
#include "BaseModel.h"
#include "WorldSpaceToScreenSpaceTransformer.h"

class Graphics
{
public:
	Graphics() = delete;
	Graphics(int WindowWidth,int WindowHeight,std::string WindowName)
		:
		Width(WindowWidth),
		Height(WindowHeight),
		WindowName(WindowName),
		CurrentWindow(glfwCreateWindow(WindowWidth,WindowHeight,WindowName.c_str(),NULL,NULL)),
		Transformer(WindowWidth,WindowHeight)
	{
		if (!CurrentWindow)
		{
			std::cout << WindowName << " Window failed to initialize!! Shutting Down OpenGl And Exitting Program....." << std::endl;
			glfwTerminate();
			ShutDownWindow = true;
		}
	}
private:
	WorldToScreenSpaceTransformer Transformer;
	GLFWwindow* CurrentWindow;
	int Width;
	int Height;
	std::string WindowName;
	//WorldToScreenSpaceTransformer Transformer;

	//Flags
	bool ShutDownWindow = false;

public:
	//Helper Functions
	GLFWwindow * GetWindowAssociated();
	bool ShouldWindowClose();
	void SetAsCurrentContext();
	int GetScreenHeight() const;
	int GetScreenWidth() const;

	//MainFunctions
public:
	/*
	IMPORTANT------
		Note- In PutPixel Y Goes from 1 to Height Whereas 
						  X Goes from 0 to Height-1
	*/
	void PutPixel(int Width,int Height,Color c); //Takes ScreenSpace Coordinates To Draw..
	void DrawLine(const Vec2& p1, const Vec2& p2, Color c) //Takes Screen Space Coordinates to draw...
	{
		DrawLine(p1.x, p1.y, p2.x, p2.y, c);
	}
	
	//This Function Takes World Space Coordinates To Draw...
	void DrawModel(BaseModel bsm);

	/*Notes About Draw Triangle---
		Consider The Left Centric Triangle Always As Standrad And Right As Inversion And You Should Be Fine...*/
	//This Function Takes ScreenSpace Coordinates To Draw...
	void DrawTriangle(Vec2& P0, Vec2& P1, Vec2& P2,Color C);
	
	//Test
	void DrawFlatBottomTriangle(Vec2& V0, Vec2& V1, Vec2& V2,Color C);
	//Private Functions
private:

	void DrawLine(float x1, float y1, float x2, float y2, Color c);
	void GetNormalized(Vec2& ScreenCoordinates);

	void DrawFlatTopTriangle(Vec2& V0, Vec2& V1, Vec2& V2,Color C);
};