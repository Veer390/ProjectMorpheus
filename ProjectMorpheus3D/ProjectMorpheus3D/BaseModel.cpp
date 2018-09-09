#include "BaseModel.h"

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

std::vector<Vec3> BaseModel::GetVertices()
{
	return Vertices;
}

std::vector<int> BaseModel::GetIndices()
{
	return Indices;
}


