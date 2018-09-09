#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Graphics.h"
#include "Mat3.h"
#include "Vec3.h"
#include "WorldSpaceToScreenSpaceTransformer.h"

#include "Cube.h"

class Game
{
public:
	Game() = delete; //Cannot Default Construct Game..
	Game(std::string Identifier, Graphics& gfx);

private:
	std::string Identifier;
	Graphics gfx;
	WorldToScreenSpaceTransformer Transformer;

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

	//Test Code
public:
	Cube TestCube;
};