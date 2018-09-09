#pragma once
#include <iostream>
#include <vector>

#define UP_ARROW         265;
#define LEFT_ARROW       263;
#define RIGHT_ARROW      262;
#define DOWN_ARROW       264;
#define SPACE_BAR        32;

#define LEFT_SHIFT       340;
#define RIGHT_SHIFT      344;

#define L_CONTROL        341;
#define R_CONTROL        345;

#define L_ALT            342;
#define R_ALT            346;

#define INSERT           260;
#define HOME             268;
#define PG_UP            266;
#define DELETE           261;
#define END              269;
#define PG_DN            267;

#define NUMPAD_0         320;
#define NUMPAD_1         321;
#define NUMPAD_2         322;
#define NUMPAD_3         323;
#define NUMPAD_4         324;
#define NUMPAD_5         325;
#define NUMPAD_6         326;
#define NUMPAD_7         327;
#define NUMPAD_8         328;
#define NUMPAD_9         329;

#define PLUS_KEY         334;
#define STAR_KEY         332;
#define SLASH_KEY        331;
#define NUMLOCK_KEY      282;

#define ENTER_KEY        257;
#define NUMPAD_ENTER_KEY 335;

#define NUMPAD_PLUS_KEY  333;
#define NUMPAD_MINUS_KEY 334;

class Keyboard
{

public:
	bool keys[1024];
public:
	Keyboard()
	{
		for (auto& i : keys)
		{
			i = false;
		}
	}

public:
	bool CheckKeyIsPressed(int keycode)
	{
		if (keys[keycode] == true)
		{
			keys[keycode] = false;
			return true;

		}
		return false;
	}

};