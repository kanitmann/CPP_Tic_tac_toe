#include<iostream>

using namespace std;

int win_checker()
{
    return 0;
}

char printer(char board[][3], int m)
{
    cout<<endl<<"---------------------"<<endl;
    for(int i = 0; i < 3; i++)
    {

        for(int j=0; j < 3 ; j++)
        {
            cout<<" | "<<board[i][j]<<" | ";
        }
        cout<<endl<<"---------------------"<<endl;


    }
    return '0';
}

int placeO(char board[][3], int m, int i)
{

}

int placeX(char board[][3], int m, int i)
{

}

int main()
{
    int m = 3;
    int place = 0;
    char board[][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int state[][3] = {{'0','0','0'},{'0','0','0'},{'0','0','0'}};
    cout<<"Welcome to Tic Tac Toe \n\n 'O' goes first, where would you like to place your 'O'?";
    printer(board, m);
    for(int i = 0 ; i < 9 ; i++)
    {
        cin >> place;
        i%2==0 ? placeO(board ,m , i) : placeX(board ,m, i); 
    }
    return 0;
}