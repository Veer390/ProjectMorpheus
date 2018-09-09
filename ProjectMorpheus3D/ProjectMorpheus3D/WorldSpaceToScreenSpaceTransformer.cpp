#include "WorldSpaceToScreenSpaceTransformer.h"

Vei3 WorldToScreenSpaceTransformer::TransformedToScreenSpace(Vec3 VectorToBeTransformed)
{
	Vei3 Temporary;
	Temporary.x = (VectorToBeTransformed.x + 1)*WindowWidth / 2;
	Temporary.y = (VectorToBeTransformed.y + 1)*WindowHeight / 2;
	//Temp.Vec2<int>::x = (VectorToBeTransformed.x + 1)*WindowWidth / 2;
	//Temp._Vec2<int>::y = (VectorToBeTransformed.y + 1)*WindowHeight / 2;
	//return Temp;
	return Temporary;

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
