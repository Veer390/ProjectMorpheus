#include "Game.h"

//Main Game Loop Is Initiated Here
void Game::GameLoop()
{
	ComposeFrame();
	DrawFrame();
}

bool Game::IsGameOver()
{
	return QuitGame;
}


Game::Game(std::string Identifier, Graphics & gfx)
	:
	Identifier(Identifier),
	gfx(gfx)
{
#ifdef DEBUG
	std::cout << "Game Initialized Successfully... IDENTIFIER : " << Identifier << std::endl;
#endif
}

void Game::ComposeFrame()
{

}

void Game::DrawFrame()
{
	gfx.DrawLine({ 0,0 }, { 1280,1280 }, { 255,0,0 });
}

