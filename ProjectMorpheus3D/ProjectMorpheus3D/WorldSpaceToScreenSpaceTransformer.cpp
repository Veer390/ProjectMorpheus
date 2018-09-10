#include "WorldSpaceToScreenSpaceTransformer.h"

Vei3 WorldToScreenSpaceTransformer::TransformedToScreenSpace(Vec3 VectorToBeTransformed)
{
	const float zInv = 1.0f / VectorToBeTransformed.z;
	// divide all position components and attributes by z
	// (we want to be interpolating our attributes in the
	//  same space where the x,y interpolation is taking
	//  place to prevent distortion)
	VectorToBeTransformed *= zInv;
	// adjust position x,y from perspective normalized space
	// to screen dimension space after perspective divide
	VectorToBeTransformed.x = (VectorToBeTransformed.x + 1.0f) * xFactor;
	VectorToBeTransformed.y = (-VectorToBeTransformed.y + 1.0f) * yFactor;
	// store 1/z in z (we will need the interpolated 1/z
	// so that we can recover the attributes after interp.)
	VectorToBeTransformed.z = zInv;

	Vei3 Temp;
	Temp.x = VectorToBeTransformed.x;
	Temp.y = VectorToBeTransformed.y;
	return Temp;

	/*Vei3 Temporary;
	Temporary.x = (VectorToBeTransformed.x + 1)*WindowWidth / 2;
	Temporary.y = (VectorToBeTransformed.y + 1)*WindowHeight / 2;

	return Temporary;*/

	/*Vei3 Temporary;
	Temporary.x = ((VectorToBeTransformed.x + 1)*WindowWidth / 2) / VectorToBeTransformed.z;
	Temporary.y = ((VectorToBeTransformed.y + 1)*WindowHeight / 2) / VectorToBeTransformed.z;
	return Temporary;*/
}

void WorldToScreenSpaceTransformer::GetTransformedToScreenSpace(Vec3 & VectorToBeTransformed)
{
	VectorToBeTransformed.x = (VectorToBeTransformed.x + 1)*WindowWidth / 2;
	VectorToBeTransformed.y = (VectorToBeTransformed.y + 1)*WindowHeight / 2;
}

/*void WorldToScreenSpaceTransformer::ChangeWindowAssigned(const Graphics * gfx)
{
	this->gfx = gfx;
	WindowWidth = gfx->GetScreenWidth();
	WindowHeight = gfx->GetScreenHeight();
}*/

Vei3 WorldToScreenSpaceTransformer::PerSpectiveTransformedToScreenSpace(Vec3 VectorToBeTransformed)
{
	Vei3 Temporary;
	Temporary.x = ((VectorToBeTransformed.x + 1)*WindowWidth / 2) / VectorToBeTransformed.z;
	Temporary.y = ((VectorToBeTransformed.y + 1)*WindowHeight / 2) / VectorToBeTransformed.z;
	return Temporary;
}
