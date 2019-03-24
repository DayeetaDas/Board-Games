/*This is the player vs computer(beatable) version of the famous board game Connect 4*/
#include "pch.h"
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;
char board[6][7] = { '-','-','-','-','-','-','-',//this is the matrix that stores the game board
					'-','-','-','-','-','-','-',
					'-','-','-','-','-','-','-',
					'-','-','-','-','-','-','-',
					'-','-','-','-','-','-','-',
					'-','-','-','-','-','-','-' };
char p1 = '*', p2 = '#';//this is a game in the console so '*' and '#' are used instead of discs for the 2 p1s.
int col = 0, i = 0, j = 0, n2 = 0;
int zero = 5, one = 5, two = 5, three = 5, four = 5, five = 5, six = 5;//stores the last row element of each column
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
				board[zero][0] = p1;
			if (col == 1 && board[one][1] == '-')
				board[one][1] = p1;
			if (col == 2 && board[two][2] == '-')
				board[two][2] = p1;
			if (col == 3 && board[three][3] == '-')
				board[three][3] = p1;
			if (col == 4 && board[four][4] == '-')
				board[four][4] = p1;
			if (col == 5 && board[five][5] == '-')
				board[five][5] = p1;
			if (col == 6 && board[six][6] == '-')
				board[six][6] = p1;
		}
	}
}
void computer_input()
{
	srand(time(NULL));
	col = rand() % 6;
}
void computer_move()
{
	for (i = 0; i <6; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (col == 0 && board[zero][0] == '-')
				board[zero][0] = p2;
			if (col == 1 && board[one][1] == '-')
				board[one][1] = p2;
			if (col == 2 && board[two][2] == '-')
				board[two][2] = p2;
			if (col == 3 && board[three][3] == '-')
				board[three][3] = p2;
			if (col == 4 && board[four][4] == '-')
				board[four][4] = p2;
			if (col == 5 && board[five][5] == '-')
				board[five][5] = p2;
			if (col == 6 && board[six][6] == '-')
				board[six][6] = p2;
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
void check_win()//checks for a player who has got 4 consecutive moves and declares the winner.If none of them
{                //have been able to win then it declares a tie
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (board[i][j] == p1 && board[i][j + 1] == p1 && board[i][j + 2] == p1 && board[i][j + 3] == p1)
				winner = p1;
			if (board[i][j] == p1 && board[i + 1][j] == p1 && board[i + 2][j] == p1 && board[i + 3][j] == p1)
				winner = p1;
			if (board[i][j] == p1 && board[i + 1][j + 1] == p1 && board[i + 2][j + 2] == p1 && board[i + 3][j + 3] == p1)
				winner = p1;
			if (board[i][j + 3] == p1 && board[i + 1][j + 2] == p1 && board[i + 2][j + 1] == p1 && board[i + 3][j] == p1)
				winner = p1;
			
			if (board[i][j] == p2 && board[i][j + 1] == p2 && board[i][j + 2] == p2 && board[i][j + 3] == p2)
				winner = p2;
			if (board[i][j] == p2 && board[i + 1][j] == p2 && board[i + 2][j] == p2 && board[i + 3][j] == p2)
				winner = p2;
			if (board[i][j] == p2 && board[i + 1][j + 1] == p2 && board[i + 2][j + 2] == p2 && board[i + 3][j + 3] == p2)
				winner = p2;
			if (board[i][j + 3] == p2 && board[i + 1][j + 2] == p2 && board[i + 2][j + 1] == p2 && board[i + 3][j] == p2)
			winner = p2;
		}
	}
}
int main()//main function
{
	draw_board();
	int c = 0;
	while (1)
	{
		c++;
		user_input();
		check_input();
		decrement();
		computer_input();
		computer_move();
		decrement();
		draw_board();
		check_win();
		if (winner == p1)
		{
			cout << "The winner is p1!" << endl;
			break;
		}
		else if (winner == p2)
		{
			cout << "The winner is p2!" << endl;
			break;
		}
		else if (c == 42)
		{
			cout << "Game Over! It is a tie!" << endl;
			break;
		}
	}
	return 0;
}
