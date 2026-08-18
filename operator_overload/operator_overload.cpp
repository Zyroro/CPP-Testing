#include <iostream>

class Vector2
{
private:
	int x;
	int y;

public:
	Vector2() = default;
	Vector2(int x, int y) : x(x), y(y) {};

	// Operator Overload
	/*
	*   @brief Overloads the + operator to add two Vector2 objects.
	* 
	*	You can think of operator+ as controls + (argument)
	*
	*   This allows Vector2 objects to be added using:
	*       Vector2 c = a + b;
	*
	*   Which is equivalent to:
	*       Vector2 c = a.operator+(b);
	*/

	Vector2 operator+(const Vector2& other)
	{
		return Vector2(x + other.x, y + other.y);
	}

	/*
	*	@brief Allows std::cout to print out a Vector2 object
	* 
	*	std::ostream represents an output stream, such as std::cout.
	* 
	*	friend to declare that the function is not part of the class but can still its data member.
	*	Used in this case because the control of operator is defaulted to "this" in classes.
	*/

	friend std::ostream& operator<<(std::ostream& output, const Vector2& vector) // std::cout operator.<< vector
	{
		output << vector.x << ", " << vector.y;
		return output;
	}

	/* Other example of operator overload */
	Vector2 operator-(const Vector2& other)
	{
		return Vector2(x - other.x, y - other.y);
	}

	bool operator==(const Vector2& other) const // Must add const according to C++20 documents.
	{
		return (x == other.x && y == other.y);
	}
};

int main()
{
	Vector2 positionA(2, 5);
	Vector2 positionB(3, 6);

	// Addition
	Vector2 positionC = positionA + positionB;
	std::cout << positionC << '\n';

	// Substraction
	Vector2 positionD = positionA - positionB;
	std::cout << positionD << '\n';

	// Comparision
	Vector2 positionE(1, 1);
	Vector2 positionF(1, 1);

	if (positionE == positionF)
	{
		std::cout << "Same!!";
	}
}