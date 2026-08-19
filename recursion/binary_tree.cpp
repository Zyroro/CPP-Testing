#include <iostream>

struct Node
{
	int value;
	Node* left;
	Node* right;
};

void print(Node* node)
{
	if (node == nullptr) return;
	
	std::cout << node->value << '\n';

	print(node->left);
	print(node->right);
}

int main()
{
	Node* first = new Node{ 10, nullptr, nullptr };
	Node* second = new Node{ 5, nullptr, nullptr };
	Node* third = new Node{ 20, nullptr, nullptr };

	first->left = second; // Left must be smaller than 10
	first->right = third; // Right must be bigger than 10

	print(first);
	return 0;	
}