#include "pch.h"
#include<iostream>
using namespace std;
int n1 = 0, n2 = 0;
char input = ' ';
void instructions()
{
	cout << "Hello this is the game of the Tower of Hanoi in the C++ Console." << endl;
	cout << "The 3 discs are arranged in the tower as shown below.PLease enter" << endl;
	cout << "The discs in the two towers that are empty. Note that u can only " << endl;
	cout << "move the disc above first. After u press s the computer is going to " << endl;
	cout << "arrange the discs back in ascending order." << endl;
}
void draw()
{
	cout << "This is the tower:" << endl;
	cout << "           1     2" << endl;
	cout << "   |       |     |" << endl;
	cout << "   |       |     |" << endl;
	cout << "  ***      |     |" << endl;
	cout << " *****     |     |" << endl;
	cout << "*******    |     |" << endl;
}
void user_input()
{
	cout << "Enter the number of the rod where u want to place the first disc:" << endl;
	cin >> n1;
	cout << "Enter the number of the rod where u want to place the second disc:" << endl;
	cin >> n2;
}
void check_and_draw()
{
	if ((n1 > 2 || n1 < 1) || (n2 > 2 || n1 < 1))
		user_input();
	if (n1 == 1 && n2 == 2)
	{
		cout << "This is the tower:" << endl;
		cout << "           1     2" << endl;
		cout << "   |       |     |" << endl;
		cout << "   |       |     |" << endl;
		cout << "   |       |     |" << endl;
		cout << "   |       |     |" << endl;
		cout << "*******   ***  *****" << endl;
	}
	else if (n1 == 2 && n2 == 1)
	{
		cout << "This is the tower:" << endl;
		cout << "           1     2" << endl;
		cout << "   |       |     |" << endl;
		cout << "   |       |     |" << endl;
		cout << "   |       |     |" << endl;
		cout << "   |       |     |" << endl;
		cout << "*******  *****  ***" << endl;
	}
}
void solve()
{
	if (n1 == 1 && n2 == 2)
	{
		cout << "Stage 1:" << endl;
		cout << "This is the tower:" << endl;
		cout << "           1     2" << endl;
		cout << "   |       |     |" << endl;
		cout << "   |       |     |" << endl;
		cout << "   |       |     |" << endl;
		cout << "   |       |    ***" << endl;
		cout << "*******    |   *****" << endl;


		cout << "Stage 2:" << endl;
		cout << "This is the tower:" << endl;
		cout << "           1      2" << endl;
		cout << "   |       |      |" << endl;
		cout << "   |       |      |" << endl;
		cout << "   |       |      |" << endl;
		cout << "   |       |     ***" << endl;
		cout <<  "  |    ******* *****" << endl;

		cout << "Stage 3:" << endl;
		cout << "This is the tower:" << endl;
		cout << "           1      2" << endl;
		cout << "   |       |      |" << endl;
		cout << "   |       |      |" << endl;
		cout << "   |      ***     |" << endl;
		cout << "   |     *****    | " << endl;
		cout << "   |    *******   |" << endl;
	}
	if (n1 == 2 && n2 == 1)
	{
		cout << "Stage 1:" << endl;
		cout << "This is the tower:" << endl;
		cout << "           1     2" << endl;
		cout << "   |       |     |" << endl;
		cout << "   |       |     |" << endl;
		cout << "   |       |     |" << endl;
		cout << "   |      ***    |" << endl;
		cout << "*******  *****   |" << endl;


		cout << "Stage 2:" << endl;
		cout << "This is the tower:" << endl;
		cout << "           1       2" << endl;
		cout << "   |       |       |" << endl;
		cout << "   |       |       |" << endl;
		cout << "   |       |       |" << endl;
		cout << "   |      ***      |" << endl;
		cout << "   |     *****  *******" << endl;

		cout << "Stage 3:" << endl;
		cout << "This is the tower:" << endl;
		cout << "           1       2" << endl;
		cout << "   |       |       |" << endl;
		cout << "   |       |       |" << endl;
		cout << "   |       |      *** " << endl;
		cout << "   |       |     *****" << endl;
		cout << "   |       |    *******" << endl;
	}
}
int main()
{
	instructions();
	draw();
	user_input();
	check_and_draw();
	while (1)
	{
		cout << "Press 's' to solve:" << endl;
		cin >> input;
		if (input == 's')
		{
			solve();
			break;
		}
		else if (input != 's')
			continue;
	}
	return 0;
}