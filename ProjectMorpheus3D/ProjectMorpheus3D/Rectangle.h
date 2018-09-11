#pragma once
#include<iostream>
#include<string>
#include<vector>

#include "Vec3.h"

class Rectangle
{
private:
	Vec3 TopLeft;
	Vec3 TopRight;
	Vec3 BottomLeft;
	Vec3 BottomRight;

public:
	Rectangle(Vec3 TopRight,Vec3 TopLeft,Vec3 BottomLeft,Vec3 BottomRight);

	//Helper Functions
public:
	//Starts From Top Right Then Top Left Then Bottom Left Then Bottom Right
	std::vector<Vec3> GetRectangleVertices();
	void SetRectangle(Vec3 TopRight, Vec3 TopLeft, Vec3 BottomLeft, Vec3 BottomRight);
		

};