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
