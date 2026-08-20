#include <iostream>
#include <conio.h>
#include "input.h"

// =====================================================================
// =====================================================================
// =====================================================================

class Player
{
public:
	bool handleInput(inputAction action)
	{
		switch (action)
		{
		case inputAction::UP:
			std::cout << "UP" << '\n';
			return true;

		case inputAction::LEFT:
			std::cout << "LEFT" << '\n';
			return true;

		case inputAction::DOWN:
			std::cout << "DOWN" << '\n';
			return true;

		case inputAction::RIGHT:
			std::cout << "RIGHT" << '\n';
			return true;
		}
		return false;
	}
};

class Inventory
{
private:
	bool m_isInventoryOpen = false;

public:
	bool handleInput(inputAction action)
	{
		switch (action)
		{
		case inputAction::INVENTORY:
			if (!m_isInventoryOpen)
			{
				std::cout << "Opened Inventory" << '\n';
				m_isInventoryOpen = true;
			}
			else
			{
				std::cout << "Closed Inventory" << '\n';
				m_isInventoryOpen = false;
			}
			return true;;
		}
		return m_isInventoryOpen;
	}

	bool isOpened() const
	{
		return m_isInventoryOpen;
	}
};

class Game
{
private:
	Player player;
	Inventory inventory;

public:
	inputAction getInput()
	{
		char input = _getch();

		input = std::tolower(input);

		switch (input)
		{
		case KEY_MOVE_UP:
			return inputAction::UP;

		case KEY_MOVE_LEFT:
			return inputAction::LEFT;

		case KEY_MOVE_DOWN:
			return inputAction::DOWN;

		case KEY_MOVE_RIGHT:
			return inputAction::RIGHT;

		case KEY_INVENTORY:
			return inputAction::INVENTORY;
		}
		return inputAction::UNKNOWN;
	};

	void handleInput()
	{
		inputAction action = getInput();

		if (inventory.handleInput(action))
			return;

		if (player.handleInput(action))
			return;
	}
};

// =====================================================================
// =====================================================================
// =====================================================================

int main()
{
	Game game;

	while (true)
	{
		game.handleInput();
	}
	return 0;
}