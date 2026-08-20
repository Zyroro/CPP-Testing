#include <iostream>
#include <Windows.h>
#include <conio.h>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
bool changeColor = false;

struct Player
{
    int row = 1;
    int col = 1;
} player;

char maze[6][10] =
{
    "#########",
    "#       #",
    "# ### # #",
    "# #   # #",
    "#    #E #",
    "#########"
};

void draw()
{
    system("cls");

    for (int row = 0; row < 6; row++)
    {
        WORD color = changeColor ?
            (0 | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY) :
            14;

        for (int col = 0; col < 9; col++)
        {
            if (maze[row][col] == '#')
            {
                SetConsoleTextAttribute(console, color);
                std::cout << "墙";
                SetConsoleTextAttribute(console, 15);
            }
            else if (row == player.row && col == player.col)
            {
                std::cout << "人";
            }
            else if (maze[row][col] == 'E')
            {
                SetConsoleTextAttribute(console, 11);
                std::cout << "出";
                SetConsoleTextAttribute(console, 15);
            }
            else
            {
                std::cout << maze[row][col] << ' ';
            }
        }

        std::cout << '\n';
    }
}

bool solveMaze(int row, int col)
{
    /* Collision */
    if (maze[row][col] == '#')
    {
        return false;
    }

    if (maze[row][col] == '.')
    {
        return false;
    }

    /* MOVE THE PLAYER */
    player.row = row;
    player.col = col;

    draw();
    Sleep(200);

    /* Base Case (Win) */
    if (maze[row][col] == 'E')
    {
        return true;
    }

    maze[row][col] = '.'; // Mark visited grid

    /* TRY UP */
    if (solveMaze(row - 1, col))
    {
        return true;
    }

    /* TRY LEFT */
    if (solveMaze(row, col - 1))
    {
        return true;
    }

    /* TRY DOWN */
    if (solveMaze(row + 1, col))
    {
        return true;
    }

    /* TRY RIGHT */
    if (solveMaze(row, col + 1))
    {
        return true;
    }

    /* Backtrack */
    player.row = row;
    player.col = col;

    draw();
    Sleep(200);

    return false;
}

// solveMaze(1, 1) -> solveMaze(0, 1), False -> solveMaze(1, 0), False -> solveMaze(2, 0), Player Moved -> Repeat until E.
// Backtrack basically returns to the TRY as false and then it goes backwards.

int main()
{
    /* Allows UTF-8 */
    SetConsoleOutputCP(CP_UTF8);

    // Draw Map
    draw();

    Sleep(500);

    // Backtracking
    if (solveMaze(player.row, player.col))
    {
        std::cout << "\nThere's a solution!\n";
    }
    else
    {
        std::cout << "\nNo solution!\n";
    }

    return 0;
}