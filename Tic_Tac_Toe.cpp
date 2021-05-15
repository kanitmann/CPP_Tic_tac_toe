#include <iostream>

using namespace std;

int board[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int state[][3] = {{9, 9, 9}, {9, 9, 9}, {9, 9, 9}};

int win_checker(int board[][3], int m)
{
    cout << "\n \t Winchecker working";
    return 0;
}

int printer(int board[][3], int m)
{
    cout << endl
         << "---------------------" << endl;
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            cout << " | " << board[i][j] << " | ";
        }
        cout << endl
             << "---------------------" << endl;
    }
    return 0;
}

int placement(int board[][3], int m, int i)
{
    int place;
    cout << i << "'s turn" << endl;

XAction:
    cout << "\nWhere would you like to place '" << i << "'?";
    cin >> place;
    if (state[int(place / 3)][place % 3 - 1] == 0 || state[int(place / 3)][place % 3 - 1] == 1)
    {
        cout << "\nAlready filled or point not valid, please retry.";
        goto XAction;
    }

    for (int j = 1; j <= 9; j++)
    {
        if (j == place)
        {
            state[int(j / 3)][j % 3 - 1] = i;
            printer(state, m);
            break;
        }
    }

    win_checker(::board, 3);
    return 0;
}

int main()
{
    int m = 3;
    int place = 0;
    cout << "Welcome to Tic Tac Toe";
    printer(board, m);
    for (int i = 0; i < 9; i++)
    {
        placement(board, m, i % 2);
    }

    cout << "Printing Final:\n ";
    printer(state, m);
    return 0;
}