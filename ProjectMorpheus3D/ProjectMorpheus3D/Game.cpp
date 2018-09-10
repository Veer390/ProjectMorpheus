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


Game::Game(std::string Identifier, Graphics & gfx,Keyboard* kb)
	:
	Identifier(Identifier),
	gfx(gfx),
	Transformer(gfx.GetScreenWidth(),gfx.GetScreenHeight()),
	TestCube(1.0f),
	kbd(kb)
{
#ifdef DEBUG
	std::cout << "Game Initialized Successfully... IDENTIFIER : " << Identifier << std::endl;
#endif
}

void Game::ComposeFrame()
{
	/*
	auto a = TestCube.GetVertices();
	auto Indexes = TestCube.GetIndices();
	std::vector<Vei3> Vertices;
	for (auto i = 0; i < a.size(); i++)
	{
		Vertices.emplace_back(Transformer.TransformedToScreenSpace(a[i]));
	}

	for (int i = 0; i < Indexes.size()-1; i = i + 2)
	{
		Vec2 p1 = { float(Vertices[Indexes[i]-1].x),float(Vertices[Indexes[i]-1].y) };
		//Vec2 p2 = { float(Vertices[Indexes[i++]-1].x),float(Vertices[Indexes[i++]-1].y) };
		Vec2 p2 = { float(Vertices[Indexes[i+1] - 1].x),float(Vertices[Indexes[i+1] - 1].y) };
		gfx.DrawLine(p1,p2, { 255,255,255 });
	}*/
}

void Game::DrawFrame()
{
	Vec2 p0 = { 250.0f,250.0f };
	Vec2 p1 = { 100.0f,1000.0f };
	Vec2 p2 = { 800.0f,1000.0f };

	gfx.DrawFlatBottomTriangle(p0, p1, p2, { 255,255,255 });
	//gfx.DrawTriangle(p0,p1 , p2, { 255,255,255 });

	//Getting The Cube To Origin For PErforming The Rotation....
	//Rotation Must Be Performed With Respect to 0,0,0 always if it has to be Uniformed
	/*if (TestFlag)
	{
		for (auto& i : TestCube.GetVertices())
		{
			i += {0.0f, 0.0f, -2.0f};
		}
	}
	
	//Rotating The TestCube However We Want By Using These Keys
	if (kbd->CheckKeyIsPressed(265))
	{
		TestCube.RotateX(theta);
	}
	if (kbd->CheckKeyIsPressed(263))
	{
		TestCube.RotateY(theta);
	}
	if (kbd->CheckKeyIsPressed(262))
	{
		TestCube.RotateZ(theta);
	}

	//Pushing The Cube Away From The Camera So That We Can actually See The Perspective Projection Of The Cube
	//This is Going On Every Frame Because We Want To rotate The Cube At The Screen Origin 0,0,0 As There is No Model Origin 
	//And Also View It By Pushing it a Little Away from the eye so that we can see the perspective projection
	for (auto& i : TestCube.GetVertices())
	{
		i += {0.0f, 0.0f, 2.0f};
	}
	TestFlag = true;
	//BaseModel bsm = TestCube::BaseModel;

	//Drawing the cube With BSM Component inside it...
	gfx.DrawModel(TestCube);
	//gfx.DrawLine({ 320,960 }, { 960,960 }, { 255,0,0 });*/
}

