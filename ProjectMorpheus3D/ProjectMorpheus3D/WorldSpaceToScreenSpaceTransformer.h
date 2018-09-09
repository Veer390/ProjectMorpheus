#pragma once
#include<iostream>
#include<string>
#include<vector>

#include "Vec3.h"
#include "Vec2.h"
#include "Mat3.h"
#include "Mat2.h"

class WorldToScreenSpaceTransformer
{
public:
	WorldToScreenSpaceTransformer() = delete; //Delete The Default Constructor
	WorldToScreenSpaceTransformer(int Width,int Height) //Minimum gfx Required For This to Work..
		:
		WindowWidth(Width),
		WindowHeight(Height)
	{	
		//WindowWidth = gfx->GetScreenWidth();
		//WindowHeight = gfx->GetScreenHeight();
	}

private:
	//const Graphics* gfx;
	int WindowWidth;
	int WindowHeight;

	//Main functions associated with the class
public:
	Vei3 TransformedToScreenSpace(Vec3 VectorToBeTransformed);
	void GetTransformedToScreenSpace(Vec3& VectorToBeTransformed);

	//Helper Functions
public:
	//void ChangeWindowAssigned(const Graphics* gfx);
};