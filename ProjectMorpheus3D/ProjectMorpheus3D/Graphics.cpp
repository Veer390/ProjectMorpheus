#include "Graphics.h"
GLFWwindow * Graphics::GetWindowAssociated()
{
	return CurrentWindow;
}

bool Graphics::ShouldWindowClose()
{
	ShutDownWindow = glfwWindowShouldClose(CurrentWindow);
	return ShutDownWindow;
}

void Graphics::SetAsCurrentContext()
{
	glfwMakeContextCurrent(CurrentWindow);
}

int Graphics::GetScreenHeight() const
{
	return Height;
}

int Graphics::GetScreenWidth() const
{
	return Width;
}

void Graphics::PutPixel(int Width, int Height,Color c)
{
	//float xFactor = float(Width) / 2.0f;
	//float yFactor = float(Height) / 2.0f;

	_Vec2<float> Final = { -1.0f,1.0f };
	int x = Width;
	int y = Height;
	Vec2 Offset = { float(x),float(y) };
	GetNormalized(Offset);
	int addx = 0;
	int Suby = 0;
	if (Width >= this->Width/2)
	{
		addx = 1;
	}
	if (Height >= this->Height/2)
	{
		Suby = 1;
	}
	Final.x = Final.x + Offset.x;
	Final.y = Final.y - Offset.y;
	//Final.x = Final.x + addx;
	//Final.y = Final.y - Suby;

	glColor3f(c.GetNormaliedR(), c.GetNormaliedG(), c.GetNormaliedB());
	glBegin(GL_POINTS);
	glVertex2f(Final.x,Final.y);
	glEnd();



	/*glColor3f(c.GetNormaliedR(), c.GetNormaliedG(), c.GetNormaliedB());
	//Temp.x = -1 * Temp.x;
	glBegin(GL_POINTS);
	glVertex2f()
	glEnd();*/
	/*Vec2 Temp = { float(Width),float(Height) };
	GetNormalized(Temp);
	
	Vec2 Origin = { float(this->Width / 2),float(this->Height / 2) };

	if (Width > Origin.x && Height < Origin.y) //1st Coordinate
	{
		glColor3f(c.GetNormaliedR(), c.GetNormaliedG(), c.GetNormaliedB());
		glBegin(GL_POINTS);
		glVertex2f(Temp.x, Temp.y);
		glEnd();
	}

	if (Width < Origin.x && Height < Origin.y) //2nd Coordinate
	{
		glColor3f(c.GetNormaliedR(), c.GetNormaliedG(), c.GetNormaliedB());
		Temp.x = -1 * Temp.x;
		glBegin(GL_POINTS);
		glVertex2f(Temp.x, Temp.y);
		glEnd();
	}

	if (Width < Origin.x && Height > Origin.y) //3rd Coordinate
	{
		glColor3f(c.GetNormaliedR(), c.GetNormaliedG(), c.GetNormaliedB());
		Temp.x = -1 * Temp.x;
		Temp.y = -1 * Temp.y;
		glBegin(GL_POINTS);
		glVertex2f(Temp.x, Temp.y);
		glEnd();
	}

	if (Width > Origin.x && Height > Origin.y) //3rd Coordinate
	{
		Temp.y = -1 * Temp.y;
		glColor3f(c.GetNormaliedR(), c.GetNormaliedG(), c.GetNormaliedB());
		glBegin(GL_POINTS);
		glVertex2f(Temp.x, Temp.y);
		glEnd();
	}*/

	/*float x = Width;
	float y = Height;
	y = -1 * y;
	//x = x - this->Width;
	//y = y + this->Height;
	x = x / this->Width;
	y = y / this->Height;
	glColor3f(c.GetNormaliedR(), c.GetNormaliedG(), c.GetNormaliedB());
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	//glVertex2f(x / Graphics::ScreenWidth, y / Graphics::ScreenHeight);
	glEnd();*/

}

void Graphics::DrawModel(BaseModel bsm)
{
	auto a = bsm.GetVertices();
	auto Indexes = bsm.GetIndices();
	std::vector<Vei3> Vertices;
	for (auto i = 0; i < a.size(); i++)
	{
		Vertices.emplace_back(Transformer.TransformedToScreenSpace(a[i]));
	}

	for (int i = 0; i < Indexes.size() - 1; i = i + 2)
	{
		Vec2 p1 = { float(Vertices[Indexes[i] - 1].x),float(Vertices[Indexes[i] - 1].y) };
		//Vec2 p2 = { float(Vertices[Indexes[i++]-1].x),float(Vertices[Indexes[i++]-1].y) };
		Vec2 p2 = { float(Vertices[Indexes[i + 1] - 1].x),float(Vertices[Indexes[i + 1] - 1].y) };
		DrawLine(p1, p2, { 255,255,255 });
	}
}

void Graphics::DrawTriangle(Vec2 & P0, Vec2 & P1, Vec2 & P2,Color C)
{
	Vec2* V0 = &P0;
	Vec2* V1 = &P1;
	Vec2* V2 = &P2;

	//V0 Ends Up At The Top..
	if (V0->y > V1->y)
		std::swap(V0, V1);
	if (V0->y > V2->y)
		std::swap(V0, V2);

	//V1 Ends Up At The Middle...
	if (V1->y > V2->y)
		std::swap(V1, V2);

	if (V1->y == V2->y)
	{
		if (V0->y < V1->y)//Natural Flat Bottom
		{
			if (V1->x > V2->x)
				std::swap(V1, V2);
			DrawFlatBottomTriangle(*V0, *V1, *V2, C);
		}

		if (V0->y > V1->y)//Natural Flat Top
		{
			if (V1->x > V2->x)
				std::swap(V1, V2);
			DrawFlatTopTriangle(*V0, *V1, *V2, C);
		}
	}

	else if (V0->y == V2->y)
	{
		if (V1->y < V2->y)//Natural Flat Bottom
		{
			if (V0->x > V2->x)
				std::swap(V0, V2);
			DrawFlatBottomTriangle(*V1, *V0, *V2, C);
		}

		if (V1->y > V2->y)//Natural Flat Top
		{
			if (V0->x > V2->x)
				std::swap(V0, V2);
			DrawFlatTopTriangle(*V1, *V0, *V2, C);
		}
	}

	else if (V0->y == V1->y)
	{
		if (V2->y < V1->y)//Natural Flat Bottom
		{
			if (V0->x > V1->x)
				std::swap(V0, V1);
			DrawFlatBottomTriangle(*V2, *V0, *V1, C);
		}

		if (V2->y > V1->y)//Natural Flat Top
		{
			if (V0->x > V1->x)
				std::swap(V0, V1);
			DrawFlatTopTriangle(*V2, *V0, *V1, C);
		}
	}

	else //General Triangle...
	{
		//Calculate Alpha
		float AlphaValue = V1->y - V0->y / V2->y - V0->y;

		Vec2 SplittingVertex;
		SplittingVertex.x = (1 - AlphaValue)*V0->x + AlphaValue * V2->x;
		SplittingVertex.y = (1 - AlphaValue)*V0->y + AlphaValue * V2->y;

		Vec2* Vi = &SplittingVertex;

		//Vi Always Ends Up At The Right..
		if (Vi->x < V1->x)
			std::swap(Vi, V1);

		DrawFlatBottomTriangle(*V1, *Vi, *V0,C);
		DrawFlatTopTriangle(*V1, *Vi, *V2,C);
	}



	/*//Make P0 Always Be The Point At The Bottom
	if (V1->y > V0->y)
		std::swap(V0, V1);
	if (V2->y > V0->y)
		std::swap(V2, V0);

	//By This Point It Is Already Understood P0 is at the top
	//Making P1 To Be In The Middle Extreme Case P1 And P0 Will Be Same Making The Triangle FlatTop
	//P2 and  P1 Will Be The Same Making The Triangle FlatBottom.
	if (V2->y > V1->y)
		std::swap(V2, V1);

	if (V2->y == V1->y) //Naturally Flat Top
	{
		DrawFlatTopTriangle(*V0, *V1, *V2,C);
	}
	else if (V0->y == V1->y) //Naturally Flat Bottom
	{
		DrawFlatBottomTriangle(*V0, *V1, *V2,C);
	}
	else  //General Triangle
	{
		//Calculate Alpha
		float AlphaValue = V1->y - V0->y / V2->y - V0->y;

		Vec2 SplittingVertex;
		SplittingVertex.x = (1 - AlphaValue)*V0->x + AlphaValue * V2->x;
		SplittingVertex.y = (1 - AlphaValue)*V0->y + AlphaValue * V2->y;

		if (SplittingVertex.x > V1->x) //Right Centric
		{
			DrawFlatTopTriangle(*V1,SplittingVertex,*V2,C);
			DrawFlatBottomTriangle(*V0,*V1,SplittingVertex,C);
		}

		if (SplittingVertex.x < V1->x) //Left Centric
		{
			DrawFlatTopTriangle(SplittingVertex,*V1,*V2,C);
			DrawFlatBottomTriangle(*V0,SplittingVertex,*V1,C);
		}
	}*/

}

void Graphics::DrawLine(float x1, float y1, float x2, float y2, Color c)
{
	const float dx = x2 - x1;
	const float dy = y2 - y1;

	if (dy == 0.0f && dx == 0.0f)
	{
		PutPixel(int(x1), int(y1), c);
	}
	else if (abs(dy) > abs(dx))
	{
		if (dy < 0.0f)
		{
			std::swap(x1, x2);
			std::swap(y1, y2);
		}

		const float m = dx / dy;
		float y = y1;
		int lastIntY;
		for (float x = x1; y < y2; y += 1.0f, x += m)
		{
			lastIntY = int(y);
			PutPixel(int(x), lastIntY, c);
		}
		if (int(y2) > lastIntY)
		{
			PutPixel(int(x2), int(y2), c);
		}
	}
	else
	{
		if (dx < 0.0f)
		{
			std::swap(x1, x2);
			std::swap(y1, y2);
		}

		const float m = dy / dx;
		float x = x1;
		int lastIntX;
		for (float y = y1; x < x2; x += 1.0f, y += m)
		{
			lastIntX = int(x);
			PutPixel(lastIntX, int(y), c);
		}
		if (int(x2) > lastIntX)
		{
			PutPixel(int(x2), int(y2), c);
		}
	}
}

void Graphics::GetNormalized(Vec2& ScreenCoordinates)
{
	ScreenCoordinates.x = ScreenCoordinates.x / (Width/2);
	ScreenCoordinates.y = ScreenCoordinates.y / (Height/2);
}

void Graphics::DrawFlatTopTriangle(Vec2 & V0, Vec2 & V1, Vec2 & V2, Color C)
{
	float YStart = V1.y;
	float YEnd = V0.y;

	//Inverse Slopes Of The Two Lines
	float m1 = (V0.x - V1.x) / (V0.y - V1.y);
	float m2 = (V0.x - V2.x) / (V0.y - V2.y);
    
	for (float i = YStart; i < YEnd; i++)
	{
		float XStart = ((V0.x - V1.x)*(i - V0.y) / (V0.y - V1.y)) + V0.x;
		float XEnd = ((V0.x - V2.x)*(i - V0.y) / (V0.y - V2.y)) + V0.x;

		for (auto j = XStart; j < XEnd; j++)
		{
			PutPixel(j, i, C);
		}
	}
	
	
}

void Graphics::DrawFlatBottomTriangle(Vec2 & V0, Vec2 & V1, Vec2 & V2, Color C)
{
	//Start And End To Draw Flat Bottom And Flat top Triangle
	float Ystart = V0.y;
	float YEnd = V1.y;

	//Inverse Slopes Of The Two Lines
	float m1 = (V0.x - V1.x) / (V0.y - V1.y);
	float m2 = (V0.x - V2.x) / (V0.y - V2.y);

	for (float i = Ystart; i < YEnd; i++)
	{
		float XStart = ((V0.x - V1.x)*(i - V0.y) / (V0.y - V1.y)) + V0.x;
		float XEnd = ((V0.x - V2.x)*(i - V0.y) / (V0.y - V2.y)) + V0.x;

		for (auto j = XStart; j < XEnd; j++)
		{
			PutPixel(j, i, C); //Here Y is i And X is J... 
		}
	}

}
