/* This is the human vs computer(beatable) board game of Reversi in C++ console*/
#include "pch.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
char board[4][4] = { '_','_','_','_','_','*','#','_','_','#','*','_','_','_','_','_' };//stores the characters of the initial board
int positions[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };//stores the positions of the game board
char human = '*', computer = '#';
int pos = 0, cpos = 0;
int n1 = 0, n2 = 0;
int c = 1;
void positions_occupied()//assigns zero to the positions which already has got a character
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			positions[1][1] = 0; positions[1][2] = 0; positions[2][1] = 0; positions[2][2] = 0;
		}
	}
}
void instructions()
{
	cout << "In this game the board already has 4 squares occupied from the start, the players will have to place their particular"
		<< "character on the board in such a way that at a particular time they can change most of the character of the opponent "
		<< "to their own character in a single row or column." << endl;
}
void position()//draws the position that the game board has
{
	cout << "1   2   3   4" << endl;
	cout << "5   6   7   8" << endl;
	cout << "9   10  11  12" << endl;
	cout << "13  14  15  16" << endl;
}
void draw_board()//draws the game board
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << board[i][j] << "  ";
		}
		cout << endl;
	}
}
void human_input()//takes input from human
{
	cout << "Enter the place where u would like to move:" << endl;
	cin >> pos;
}
void human_move()//checks and places the move if valid
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (positions[i][j] == pos && positions[i][j] != 0)
			{
				board[i][j] = human;
				n1 = i;
				n2 = j;
				break;
			}
			else if (positions[i][j] == pos && positions[i][j] == 0)
				human_input();
		}
	}
}
void human_new_board()//draws the new board after the human move
{
	for (int i = 0; i < 4; i++)
	{
		if (board[i][n2] == computer)
			board[i][n2] = human;
	}
	for (int j = 0; j < 4; j++)
	{
		if (board[n1][j] == computer)
			board[n1][j] = human;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << board[i][j] << "   ";
		}
		cout << endl;
	}
}
void computer_input()//takes the computer input
{
	srand(time(NULL));
	cpos = rand() % 15 + 1;
}
void computer_move()//places the move if valid
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (positions[i][j] == cpos && positions[i][j] != 0)
			{
				board[i][j] = computer;
				n1 = i;
				n2 = j;
				break;
			}
			else if (positions[i][j] == cpos && positions[i][j] == 0)
				computer_input();
		}
	}
}
void computer_new_board()//draws the new board after placing the computer's move
{
	for (int i = 0; i < 4; i++)
	{
		if (board[i][n2] == human)
			board[i][n2] = computer;
	}
	for (int j = 0; j < 4; j++)
	{
		if (board[n1][j] == human)
			board[n1][j] = computer;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << board[i][j] << "   ";
		}
		cout << endl;
	}
}
int Game_Over()//checks if the game is over or not
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] != '_' && board[i][j + 1] != '_' && board[i][j + 2] != '_' && board[i][j + 3] &&
				board[i + 1][j] != '_' && board[i + 1][j + 1] != '_' && board[i + 1][j + 2] != '_' && board[i + 1][j + 3] &&
				board[i + 2][j] != '_' && board[i + 2][j + 1] != '_' && board[i + 2][j + 2] != '_' && board[i + 2][j + 3] &&
				board[i + 3][j] != '_' && board[i + 3][j + 1] != '_' && board[i + 3][j + 2] != '_' && board[i + 3][j + 3] != '_')
				c = 0;
				break;
		}
	}
	return c;
}
int main()//main function
{
	positions_occupied;
	instructions();
	draw_board();
	while (1)
	{
		position();
		cout << endl;
		human_input();
		human_move();
		human_new_board();
		cout << endl;
		computer_input();
		computer_move();
		computer_new_board();
		Game_Over();
		if (c == 0)
		{
			cout << "Game Over!" << endl;
			break;
		}
	}
	return 0;
}
