#include <iostream>

/* Function pointers are pointers that point to a function. This allows functions to be passed through as arguments. */

int add(int a, int b)
{
	return a + b;
}

int substract(int a, int b)
{
	return a - b;
}

/*
*	@brief A function that calculates two integers through a function argument
*	@param *func Passes the add or subtraction function
*/

int calculate(int a, int b, int(*func)(int, int))
{
	return func(a, b);
}

int main()
{
	std::cout << calculate(1, 1, add) << '\n';
	std::cout << calculate(2, 1, substract) << '\n';
	return 0;
}