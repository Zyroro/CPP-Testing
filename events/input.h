#pragma once

#define KEY_MOVE_UP 'w'
#define KEY_MOVE_LEFT 'a'
#define KEY_MOVE_DOWN 's'
#define KEY_MOVE_RIGHT 'd'
#define KEY_INVENTORY 'g'

enum class inputAction
{
	UP,
	LEFT,
	DOWN,
	RIGHT,
	INVENTORY,
	UNKNOWN
};
