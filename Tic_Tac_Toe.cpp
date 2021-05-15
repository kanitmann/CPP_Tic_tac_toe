#include<iostream>

using namespace std;

int board[][3] = {{1,2,3},{4,5,6},{7,8,9}};
int state[][3] = {{9,9,9},{9,9,9},{9,9,9}};

int win_checker(int board[][3], int m)
{   
    cout<<"\n\tWinchecker working";
    return 0;
}

int printer(int board[][3], int m)
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

int placeO(int board[][3], int m, int i)
{
    int check = 0;
    cout<<"0's turn"<<endl;
    OAction:
    cout<<"\nWhere would you like to place '0'?";
    int place = 7;
    for(int i = 1; i<=9 ; i++)
    {
        if(i==place)
            {
                state[int(i/3)][i%3-1]=0; 
                check = 1;
                break;
            }
    }
    if(check==0)
    {
        cout<<"\nAlready filled or point not valid, please retry.";
        goto OAction;
    }
    win_checker(::board,3);
    return 0;
}

int placeX(int board[][3], int m, int i)
{
    cout<<"1's turn"<<endl;
    return 0;
}

int main()
{
    int m = 3;
    int place = 0;
    cout<<"Welcome to Tic Tac Toe";
    printer(board, m);
    for(int i = 0 ; i < 9 ; i++)
    {
        i%2==0 ? placeO(board ,m , i) : placeX(board ,m, i); 
    }

    cout<<"Printing Final:\n ";
    printer(state,m);
    return 0;
}