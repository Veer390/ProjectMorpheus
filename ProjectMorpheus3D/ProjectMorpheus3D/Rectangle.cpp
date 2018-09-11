#include "Rectangle.h"
#include <cassert>

Rectangle::Rectangle(Vec3 TopRight, Vec3 TopLeft, Vec3 BottomLeft, Vec3 BottomRight)
	:
	TopLeft(TopLeft),
	TopRight(TopRight),
	BottomLeft(BottomLeft),
	BottomRight(BottomRight)
{
	assert(TopRight.x > TopLeft.x);
	assert(TopRight.y == TopLeft.y);

	//Making Sure BottomLeft is Actually Bottom Left
	assert(BottomRight.x > BottomLeft.x);
	assert(BottomRight.y == BottomLeft.y);

	//Final Measure To Make Sure The Rectangle is Not Inverted..
	assert(BottomRight.y > TopRight.y);
}

std::vector<Vec3> Rectangle::GetRectangleVertices()
{
	std::vector<Vec3> Temp =  {TopRight,TopLeft,BottomLeft,BottomRight };
	return Temp;
}

void Rectangle::SetRectangle(Vec3 TopRight, Vec3 TopLeft, Vec3 BottomLeft, Vec3 BottomRight)
{
	//MAking Sure Top Right is Actually Top Right
	assert(TopRight.x > TopLeft.x);
	assert(TopRight.y == TopLeft.y);

	//Making Sure BottomLeft is Actually Bottom Left
	assert(BottomRight.x > BottomLeft.x);
	assert(BottomRight.y == BottomLeft.y);

	//Final Measure To Make Sure The Rectangle is Not Inverted..
	assert(BottomRight.y > TopRight.y);

	this->TopRight = TopRight;
	this->TopLeft = TopLeft;
	this->BottomLeft = BottomLeft;
	this->BottomRight = BottomRight;
	
}
