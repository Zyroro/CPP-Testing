#include <iostream>

/* Recursion is a technique of making a function call itself.
It's useful for breaking complicated problems into smaller subproblems */

/*
*   @brief a factorial function
*   @param k is denoted as k!
* 
*   The function will keep calling itself until the base case is met
*   etc factorial(2) ... factorial(1) ... factorial(0).
*/

int factorial(int k)
{
    // Recursive Case
    if (k > 0)
    {
        return k * factorial(k - 1);
    }
    // Base Case
    else
    {
        return 1;
    }
}

/*
*   @brief counts down to 1
*   @param time is the time of the countdown
*/

void countdown(int time)
{
    // Recursive Case
    if (time > 0) {
        std::cout << time << " ";
        countdown(time - 1);
    }
}

int main()
{
    std::cout << factorial(4) << '\n'; // 24
    countdown(5);
    return 0;
}