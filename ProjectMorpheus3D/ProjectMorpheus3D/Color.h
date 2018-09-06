#pragma once
#include<iostream>
#include<string>

//Note- the engine uses color data ranging from 0 to 255 
//		However Opengl uses something like 0 to 1 float value 
//		The channels r,g,b inside the object always stores an int value between 0 255 and when presenting it to Opengl We use
//The Function Get Normailzed To Transform All Channels Into the Values OpenGl Desires... 
class Color
{
	friend class Graphics;

	public:
		Color() = default;
		Color(int r, int g, int b)
			:
			r(r),
			g(g),
			b(b)
		{}

	private:
		int r = 0;
		int g = 0;
		int b = 0;

	public:
		//Compare Color To Color
		bool operator!=(Color rhs)
		{
			if (this->r == rhs.r
				&& this->g == rhs.g
				&& this->b == rhs.b)
			{
				return false;
			}
			else
				return true;
		}

		//Get Various Channels
		inline int GetR()
		{
			return r;
		}
		inline int GetG()
		{
			return g;
		}
		inline int GetB()
		{
			return b;
		}

		//SetsTheColorFrom Character Data
		void SetColorFromCharData(unsigned char R, unsigned char G, unsigned char B)
		{
			r = static_cast<int>(R);
			g = static_cast<int>(G);
			b = static_cast<int>(B);
		}

		//One Function To Set R channel G channel and B channel
		void SetRGB(int R, int G, int B)
		{
			r = R;
			g = G;
			b = B;
		}


		/*Returns The Normalized Coordinates to opengl as Opengl Only Takes In Normalized Coordinates*/
private:
		inline float GetNormaliedR()
		{
			float R = r;
			return R / 255;
		}
		inline float GetNormaliedG()
		{
			float G = g;
			return G / 255;
		}
		inline float GetNormaliedB()
		{
			float B = b;
			return B / 255;
		}

};