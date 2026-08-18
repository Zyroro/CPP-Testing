#include <iostream>
#include "template.h"

/* Template allows any function to work with different datatypes 
*  without having to write a separate function for each type 
* 
*  @tparam T the datatype of the value 
*/

template<typename T> 
void print(T content)
{
	std::cout << content << '\n';
}

/* You can also make a variadic template which accepts any number of arguments 
*  ... tells the compiler that this function is repeating
*/

template<typename... Args>
void printMulti(Args... args)
{
	((std::cout << args << '\n'), ...);
}

int main()
{
	print("Hello World!");
	print(123);
	printMulti("Hi", 12345);
	std::cout << max(2, 5); /* From The Header File */
	return 0;
}