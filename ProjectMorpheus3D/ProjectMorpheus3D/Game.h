#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Keyboard.h"
#include "Graphics.h"
#include "Mat3.h"
#include "Vec3.h"
#include "WorldSpaceToScreenSpaceTransformer.h"

#include "BaseModel.h"
#include "Cube.h"

class Game
{
public:
	Game() = delete; //Cannot Default Construct Game..
	Game(std::string Identifier, Graphics& gfx,Keyboard* kb);

private:
	std::string Identifier;
	Graphics gfx;
	WorldToScreenSpaceTransformer Transformer;
	Keyboard* kbd;

	//Flags
	bool QuitGame = false;

	//Major Functions
private:
	void ComposeFrame();
	void DrawFrame();

	//Public Visible Functions
public:
	void GameLoop();
	bool IsGameOver();

	float theta = 0.1f;
	//Test Code
public:
	Cube TestCube;

public:
	bool TestFlag = false;
};