#pragma once
#include<iostream>
#include<vector>
#include<string>

#include "Vec3.h"
#include "Mat3.h"

class BaseModel
{
public:
	BaseModel() = default;
	BaseModel(std::string Name, std::vector<Vec3> Vertices, std::vector<int> Indices);

protected:
	std::string ModelName;
	std::vector<Vec3> Vertices;
	std::vector<int> Indices;

	//Helper Functions...
public:
	std::string GetName();
	std::vector<Vec3> GetVertices();
	std::vector<int> GetIndices();
};