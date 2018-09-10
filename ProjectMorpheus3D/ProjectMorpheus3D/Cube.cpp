#include "Cube.h"

Cube::Cube(std::vector<Vec3> Vertices, std::vector<int> Indices)
	:
	BaseModel("Cube",Vertices,Indices) //Generate Cube Based On Vertices And Indices Given
{}

Cube::Cube(float side)
{
	std::vector<Vec3> _Vertices = {

	{ -side/2,side/2,side/2 },{ side / 2,side / 2,side/2 },{ side / 2,side / 2,-side / 2 },
	{ -side / 2,side / 2,-side / 2 },{ -side / 2,-side / 2,side/2 },{ side / 2,-side / 2,side/2 },
	{ side / 2,-side / 2,-side / 2 },{ -side/2,-side / 2,-side / 2 }
	};

	std::vector<int> _Indices = { 1,2,  2,3,  4,3,  4,1 ,
		5,6,  6,7,  7,8,  8,5 ,
		4,8 , 1,5,  2,6 , 3,7 };

	TriangleIndices = {
		1,2,3, 3,4,1 ,
		8,4,7, 7,3,4 ,
		8,5,7, 7,6,5 ,
		5,1,6, 6,2,1 ,
		8,1,5, 5,8,4 ,
		7,3,6, 6,2,3
	};
	BaseModel::ModelName = "Cube";
	BaseModel::Vertices = _Vertices;
	BaseModel::Indices = _Indices;
}

std::vector<int>& Cube::GetTriangleIndices()
{
	return TriangleIndices;
}

std::vector<Vec3>& Cube::GetVertices()
{
	return Vertices;
}

std::vector<int>& Cube::GetIndices()
{
	return Indices;
}

VertexAndIndex Cube::GetVerticesAndIndices()
{
	return { Vertices,Indices };
}
