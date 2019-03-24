/*This is the 2 player version of the famous board game Connect 4*/
#include "pch.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
char board[6][7] = { '-','-','-','-','-','-','-',//this is the matrix that stores the game board
					'-','-','-','-','-','-','-',
					'-','-','-','-','-','-','-',
					'-','-','-','-','-','-','-',
					'-','-','-','-','-','-','-',
					'-','-','-','-','-','-','-'};
char p1 = '*', p2 = '#';//this is a game in the console so '*' and '#' are used instead of discs for the 2 players.
char player = p1;
int col = 0, i = 0, j = 0,n2=0;
int zero = 5, one = 5, two=5, three=5, four=5, five=5, six=5;//stores the last row element of each column
char winner = ' ';
void draw_board()//draws the board
{
	cout << "0   1   2   3   4   5   6" << endl;
	cout << "__________________________" << endl;
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 7; j++)
		{
			cout << board[i][j] << "   ";
		}
		cout << endl;
	}
}
void user_input()//takes input from the user
{
	cout << "Enter the column where you would like to place your move:" << endl;
	cin >> col;
}
void check_input()//checks the input and starts placing the move starting from the bottom of each row
{
	if (col > 6 || col < 0)
	{
		cout << " The number is out of range please enter another number" << endl;
		cin >> col;
		user_input();
	}
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (col == 0 && board[zero][0] == '-')
				board[zero][0] = player;
			if (col == 1 && board[one][1] == '-')
				board[one][1] = player;
			
			if (col == 2 && board[two][2] == '-')
				board[two][2] = player;
			
			if (col == 3 && board[three][3] == '-')
			
				board[three][3] = player;
			
			if (col == 4 && board[four][4] == '-')
			
				board[four][4] = player;
			
			if (col == 5 && board[five][5] == '-')
				board[five][5] = player;
			if (col == 6 && board[six][6] == '-')
				board[six][6] = player;
		}
	}
}
void decrement()//decrements the row element after the bottom one has already been occupied
{
	if (col == 0)
		zero--;
	else if (col == 1)
		one--;
	else if (col == 2)
		two--;
	else if (col == 3)
		three--;
	else if (col == 4)
		four--;
	else if (col == 5)
		five--;
	else if (col == 6)
		six--;
}
void toggle_player()//switches the players 
{
	if (player == '*')
		player = '#';
	else if (player == '#')
		player = '*';
}
void win()//checks for a player who has got 4 consecutive moves and declares the winner.If none of them
{                //have been able to win then it declares a tie
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player)
				winner = player;
			if (board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player)
				winner = player;
			if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player)
				winner = player;
			if (board[i][j + 3] == player && board[i + 1][j + 2] == player && board[i + 2][j + 1] == player && board[i + 3][j] == player)
				winner = player;
		}
	}
}
int main()//main function
{
	int c = 0;
	while (1)
	{
		c++;
		draw_board();
		user_input();
		check_input();
		decrement();
		win();
		if (winner == player)
		{
			cout << "The winner is " << player << endl;
			break;
		}
	    if ( c==42)
		{
			cout << "It is a draw match!" << endl;
			break;
		}
		toggle_player();
	}
	return 0;
}
