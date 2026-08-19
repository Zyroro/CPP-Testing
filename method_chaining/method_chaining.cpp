#include <iostream>

class Player
{
private:
	int m_healthPts, m_attackPts;
	std::string m_name;

public:
	Player() : m_healthPts(0), m_attackPts(0), m_name("") {}

	void printStats()
	{
		std::cout << "Hp: " << m_healthPts << " Atk: " << m_attackPts << " Name: " << m_name << '\n';
	}

	/* Method Chaining */
	/*
	*	@brief Methods which returns a value to the object
	*
	*	It's a technique where you call multiple methods on the same objects in a single expression
	*/

	Player& setHealth(int healthPts)
	{
		m_healthPts = healthPts;
		return *this;
	}

	Player& setAttack(int attackPts)
	{
		m_attackPts = attackPts;
	}

	Player& setName(std::string name)
	{
		m_name = name;
		return *this;
	}
};

int main()
{
	Player Bob;
	Bob.printStats();
	return 0;
}