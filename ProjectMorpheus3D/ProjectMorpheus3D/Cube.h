#pragma once
#include<iostream>
#include<vector>
#include<string>

#include"Vec3.h"
#include"Mat3.h"

#include "VertexAndIndex.h"

class Cube
{
	std::vector<Vec3> Vertices =
	{
		{-0.5,0.5,1},{0.5,0.5,1},{0.5,0.5,0.5},
		{-0.5,0.5,0.5},{-0.5,-0.5,1},{0.5,-0.5,1},
		{0.5,-0.5,0.5},{-0.5,-0.5,0.5}
	};

	std::vector<int> Indices = { 1,2,  2,3,  4,3,  4,1 ,
							   5,6,  6,7,  7,8,  8,5 ,
							   4,8 , 1,5,  2,6 , 3,7 };

	/*std::vector<int> Indices ={ 1,2,  2,3,  4,3,  4,1 ,
								5,6,  6,7,  7,8,  8,5 ,
								};*/


public:
	std::vector<Vec3> GetVertices();
	std::vector<int> GetIndices();

	VertexAndIndex GetVerticesAndIndices();
};