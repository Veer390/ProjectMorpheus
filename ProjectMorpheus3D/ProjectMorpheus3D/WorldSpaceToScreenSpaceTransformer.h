#pragma once
#include<iostream>
#include<string>
#include<vector>

#include "Graphics.h"
#include "Vec3.h"
#include "Vec2.h"
#include "Mat3.h"
#include "Mat2.h"

class WorldToScreenSpaceTransformer
{
public:
	WorldToScreenSpaceTransformer() = delete; //Delete The Default Constructor
	WorldToScreenSpaceTransformer(Graphics& gfx) //Minimum gfx Required For This to Work..
		:
		gfx(gfx)
	{
		WindowWidth = gfx.GetScreenWidth();
		WindowHeight = gfx.GetScreenHeight();
	}

private:
	Graphics gfx;
	int WindowWidth;
	int WindowHeight;

	//Main functions associated with the class
public:
	Vei3 TransformedToScreenSpace(Vec3 VectorToBeTransformed);
	void GetTransformedToScreenSpace(Vec3& VectorToBeTransformed);

	//Helper Functions
public:
	void ChangeWindowAssigned(Graphics& gfx);
};