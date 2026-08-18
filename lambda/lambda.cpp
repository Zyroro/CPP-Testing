#include <iostream>

/* Lambda are basically anonymous functions */

/*
*	@brief A function that calculates two integers through a function argument
*	@param *func Passes a lambda function
*/

int calculate(int a, int b, int(*func)(int, int))
{
	return func(a, b);
}

int main()
{
	/* Lambda Expression */
	auto hello = []()
		{
			std::cout << "Hello World" << '\n';
		};

	hello();

	/* Passing a Lambda Expression As An Argument */
	std::cout << calculate(2, 1, [](int a, int b)
		{
			return a + b;
		}
	) << '\n';
	return 0;
}