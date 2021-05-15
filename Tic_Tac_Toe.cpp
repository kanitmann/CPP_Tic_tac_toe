#include <iostream>

using namespace std;

int board[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int state[][3] = {{9, 9, 9}, {9, 9, 9}, {9, 9, 9}};

int win_checker(int state[][3], int m)
{
    if ((state[0][0] == 1 && state[1][1] == 1 && state[2][2] == 1) || (state[0][0] == 1 && state[0][1] == 1 && state[0][2] == 1) || (state[0][0] == 1 && state[1][0] == 1 && state[2][0] == 1) || (state[1][0] == 1 && state[1][1] == 1 && state[1][2] == 1) || (state[2][0] == 1 && state[2][1] == 1 && state[2][2] == 1) || (state[1][0] == 1 && state[1][1] == 1 && state[1][2] == 1) || (state[2][0] == 1 && state[2][1] == 1 && state[2][2] == 1) || (state[0][2] == 1 && state[1][1] == 1 && state[2][1] == 1) || (state[0][0] == 0 && state[1][1] == 0 && state[2][2] == 0) || (state[0][0] == 0 && state[1][0] == 0 && state[2][0] == 0) || (state[1][0] == 1 && state[1][1] == 0 && state[1][2] == 0) || (state[2][0] == 0 && state[2][1] == 0 && state[2][2] == 0) || (state[0][0] == 0 && state[0][1] == 0 && state[0][2] == 0) || (state[1][0] == 0 && state[1][1] == 0 && state[1][2] == 0) || (state[2][0] == 0 && state[2][1] == 0 && state[2][2] == 0) || (state[0][2] == 0 && state[1][1] == 0 && state[2][1] == 0))
    {
        cout << "\n\n\tWinner found!!!\n\n";
        return 1;
    }
    else
    {
        cout << "\nRunning Win_Checker!!\n";
        return 0;
    }
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
    int winner = 0;
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

    winner = win_checker(state, 3);
    if (winner == 1)
        return 1;
    else
        return 0;
}

int main()
{
    int m = 3;
    int place = 0;
    cout << "Welcome to Tic Tac Toe";
    printer(board, m);
    int win = 0;
    for (int i = 0; i < 9; i++)
    {
        win = placement(board, m, i % 2);
        if (win == 1)
            break;
    }

    cout << "Printing Final:\n ";
    printer(state, m);
    return 0;
}

//Code by Kanit