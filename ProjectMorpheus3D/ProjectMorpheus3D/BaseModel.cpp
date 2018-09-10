#include "BaseModel.h"
#include<cmath>

BaseModel::BaseModel(std::string Name, std::vector<Vec3> Vertices, std::vector<int> Indices)
	:
	ModelName(Name),
	Vertices(Vertices),
	Indices(Indices)
{}

std::string BaseModel::GetName()
{
	return ModelName;
}

std::vector<Vec3>& BaseModel::GetVertices()
{
	return Vertices;
}

std::vector<int>& BaseModel::GetIndices()
{
	return Indices;
}

void BaseModel::RotateX(float theta)
{
	Mat3 XRotationMatrice =
	{
		1,     0      ,    0        ,
		0 ,cosf(theta), -sinf(theta),
		0 ,sinf(theta),  cosf(theta)
	};
	for (int i = 0; i < Vertices.size(); i++)
	{
		Vertices[i] = Vertices[i] * XRotationMatrice;
	}
}

void BaseModel::RotateY(float theta)
{
	Mat3 YRotationMatrice =
	{
		 cosf(theta),   0,    sinf(theta),
		     0      ,   1,        0,
		-sinf(theta),   0,    cosf(theta)
	};
	for (int i = 0; i < Vertices.size(); i++)
	{
		Vertices[i] = Vertices[i] * YRotationMatrice;
	}
}

void BaseModel::RotateZ(float theta)
{
	Mat3 ZRotationMatrice =
	{
		cosf(theta),   -sinf(theta),    0,
		sinf(theta),    cosf(theta),    0,
		    0,              0,          1
	};
	for (int i = 0; i < Vertices.size(); i++)
	{
		Vertices[i] = Vertices[i] * ZRotationMatrice;
	}
}


