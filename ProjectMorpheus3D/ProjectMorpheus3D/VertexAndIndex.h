#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Vec3.h"

struct VertexAndIndex
{
	std::vector<Vec3> Vertices;
	std::vector<int> Indexes;
};