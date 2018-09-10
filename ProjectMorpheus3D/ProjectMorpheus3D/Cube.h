#pragma once
#include<iostream>
#include<vector>
#include<string>

#include "Vec2.h"
#include "Vec3.h"
#include "Mat3.h"
#include "Mat2.h"

#include "VertexAndIndex.h"
#include"BaseModel.h"

class Cube:public BaseModel
{
public:
	Cube() = delete; //Because Base Model Cannot be Constructed Without Certain Parameters
	Cube(std::vector<Vec3> Vertices, std::vector<int> Indices);
	Cube(float side);

public:

public:
	std::vector<Vec3>& GetVertices();
	std::vector<int>& GetIndices();

	VertexAndIndex GetVerticesAndIndices();
};