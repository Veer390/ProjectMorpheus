#include "Cube.h"

std::vector<Vec3> Cube::GetVertices()
{
	return Vertices;
}

std::vector<int> Cube::GetIndices()
{
	return Indices;
}

VertexAndIndex Cube::GetVerticesAndIndices()
{
	return { Vertices,Indices };
}
