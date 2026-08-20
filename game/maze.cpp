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
    system("cls"); // Clear Console

    for (int row = 0; row < 6; row++)
    {
        WORD color = changeColor ? (0 | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY) : (14);

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

void movePlayer(int dRow, int dCol)
{
    int newRow = player.row + dRow;
    int newCol = player.col + dCol;

    /* Collision */
    if (maze[newRow][newCol] == '#') return;

    /* Update New Position */
    player.row = newRow;
    player.col = newCol;
}

void getMoveInput()
{
    char key = _getch();

    switch (key)
    {
    case 'w':
        movePlayer(-1, 0);
        break;

    case 'a':
        movePlayer(0, -1);
        break;

    case 's':
        movePlayer(1, 0);
        break;

    case 'd':
        movePlayer(0, 1);
        break;
    case 'q':
        changeColor = !changeColor;
        break;
    }
}

int main()
{
	/* Allows UTF-8 */
	SetConsoleOutputCP(CP_UTF8);

    /* Gameloop */
    while (true)
    {
        // Draw Map
        draw();

        // Send Move Input To Move Player
        getMoveInput();

        // Reached Exit
        if (maze[player.row][player.col] == 'E')
        {
            std::cout << "You win!\n";
            draw();
            break;
        }
    }
    return 0;
}