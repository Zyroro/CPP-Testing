#include <iostream>
#include <vector>

struct GameObject
{
	std::string name;
	std::vector<GameObject*> children;
};

void printHierarchy(GameObject* object, int depth = 0)
{
	for (int i = 0; i < depth; i++)
		std::cout << "  ";

	std::cout << object->name << '\n';

	for (GameObject* child : object->children)
	{
		printHierarchy(child, depth + 1);
	}
}

int main()
{
	GameObject Player{ "Player" };
	GameObject Weapon{ "Weapon" };
	GameObject Sword{ "Sword" };

	/* Player -> Weapon -> Sword */

	Player.children.push_back(&Weapon);
	Weapon.children.push_back(&Sword);

	/* Prints player's hierarchy */
	printHierarchy(&Player);
}