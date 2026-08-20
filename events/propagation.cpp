#include <iostream>
#include <conio.h>
#include "input.h"

// =====================================================================
// =====================================================================
// =====================================================================

class Game
{
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
};

class Player
{
public:
	void handleInput(inputAction action)
	{
		switch (action)
		{
		case inputAction::UP:
			std::cout << "UP" << '\n';
			break;

		case inputAction::LEFT:
			std::cout << "LEFT" << '\n';
			break;

		case inputAction::DOWN:
			std::cout << "DOWN" << '\n';
			break;

		case inputAction::RIGHT:
			std::cout << "RIGHT" << '\n';
			break;

		default:
			break;
		}
	}
};

class Inventory
{
private:
	bool m_isInventoryOpen = false;

public:
	void handleInput(inputAction action)
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

			break;

		default:
			break;
		}
	}

	bool isInventoryOpen() const
	{
		return m_isInventoryOpen;
	}
};

// =====================================================================
// =====================================================================
// =====================================================================

int main()
{
	Game game;
	Player player;
	Inventory inventory;

	while (true)
	{
		inputAction action = game.getInput();

		if (!inventory.isInventoryOpen())
		{
			player.handleInput(action);
		}
		inventory.handleInput(action);
	}
	return 0;
}