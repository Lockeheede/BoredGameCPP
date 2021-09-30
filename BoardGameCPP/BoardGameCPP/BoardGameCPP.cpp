// BoardGameCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This is practice using the coding techniques I've learned so far. Completely from scratch, no documentation, tutorials, videos. Just knowledge from reading the Learn CPP Quickly Book. 
// All Five Tasks are done as of 3:04am on 09132021. 
// Next Task is trying to figure out a tic tac toe game, tomorrow! 


#include <iostream>
#include <vector>

using namespace std;

void PrintBoard(int x, int y);
void ChangeBoard(int x, int y);
void ChangeCell();
void TicTacToe();

int main()
{
	/*
	int p_row, p_col;
	int c_row, c_col;

	//Task 1: Print the board.This needs to be a 3x3 board.So...how would I do that ?
	cout << "Print Board Rows: ";
	cin >> p_row;
	cout << "Print Board Columns: ";
	cin >> p_col;
	PrintBoard(p_row, p_col);
	//Task 2: Change the values in the board
	cout << "Change Board Rows: ";
	cin >> c_row;
	cout << "Change Board Columns: ";
	cin >> c_col;
	ChangeBoard(c_row, c_col);
	//Task 3: Change a single cell of the board
	ChangeCell();
	//Task 4: Go back to PrintBoard and ChangeBoard and make a custom sized board with user input (Done!)
	*/
	//Task 5: Tic Tac Toe
	bool ttt_playagain = true;
	char ttt_choice;
	do{
		TicTacToe();
		cout << "Play again? Y/N: ";
		cin >> ttt_choice;
		if (ttt_choice == 'y' || ttt_choice == 'Y')
		{
			ttt_playagain = true;
			TicTacToe();
		}
		else
		{
			ttt_playagain = false;
		}
	} while (ttt_playagain == true);
}

//Task 1 Complete. Potentially the easiest thing that can be done
void PrintBoard(int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			cout << "*";
		cout << endl;
	}
	cout << endl;
}

//Task 2. Fairly simple. Use cin to input a single character symbol to change the board
void ChangeBoard(int x, int y)
{
	char sym;
	cout << "Symbol: ";
	cin >> sym;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			cout << sym;
		cout << endl;
	}
	cout << endl;
}

//Task 3. A bit more complicated, but I eventually figured it out. The key is to instanciate the array with elements before hand
void ChangeCell()
{
	char sym; 
	int pos = 0;
	char board[3][3] = { {'*', '*', '*'},
						 {'*', '*', '*'},
						 {'*', '*', '*'} };
	cout << "Symbol: ";
	cin >> sym;
	while (pos < 1 || pos > 9)
	{
		cout << "Position (1-9): ";
		cin >> pos;
		if (pos >= 1 || pos <= 9)
		{
			switch(pos)
			{
			case 1:
				board[0][0] = sym;
				break;
			case 2:
				board[0][1] = sym;
				break;
			case 3:
				board[0][2] = sym;
				break;
			case 4:
				board[1][0] = sym;
				break;
			case 5:
				board[1][1] = sym;
				break;
			case 6:
				board[1][2] = sym;
				break;
			case 7:
				board[2][0] = sym;
				break;
			case 8:
				board[2][1] = sym;
				break;
			case 9:
				board[2][2] = sym;
				break;
			default:
				cout << "Try Again!\n";
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "\n" << board[i][j];
		}
		cout << endl;
	}
}

void TicTacToe()
{
	//Create the Board
	char board[3][3] = { {'_', '_', '_'},
						{'_', '_', '_'},
						{'_', '_', '_'}, };

	cout << "Welcome to Tic Tac Toe!\n";
	cout << "Here is the board\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << "the choices are 1 - 9\n";
	cout << "Do NOT choose the same number your opponent chose or you lose a turn!\n";


	//Create Player Position Chooser
	int pos1 = -1;
	int pos2 = -2;
	char sym1 = 'X', sym2 = 'O';

	//Gameover Condition
	bool gameover = false;

	//Test input
	while (gameover != true)
	{
			cout << "Player 1 enter your position between 1-9: ";
			cin >> pos1;

			if (pos1 != pos2)
			{
				switch (pos1)
				{
				case 1:
					board[0][0] = sym1;
					break;
				case 2:
					board[0][1] = sym1;
					break;
				case 3:
					board[0][2] = sym1;
					break;
				case 4:
					board[1][0] = sym1;
					break;
				case 5:
					board[1][1] = sym1;
					break;
				case 6:
					board[1][2] = sym1;
					break;
				case 7:
					board[2][0] = sym1;
					break;
				case 8:
					board[2][1] = sym1;
					break;
				case 9:
					board[2][2] = sym1;
					break;
				default:
					cout << "You didn't pick 1-9\n";
					break;
				}
			}
			else {
				cout << "That is already chosen, choose a different spot!\n";
			}
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << board[i][j];
				}
				cout << endl;
			}
			if (board[0][0] == sym1 && board[0][1] == sym1 && board[0][2] == sym1
				|| board[1][0] == sym1 && board[1][1] == sym1 && board[1][2] == sym1 || board[2][0] == sym1 && board[2][1] == sym1 && board[2][2] == sym1 || board[0][0] == sym1 && board[1][1] == sym1 && board[2][2] == sym1 || board[0][0] == sym1 && board[1][0] == sym1 && board[2][0] == sym1 || board[0][1] == sym1 && board[1][1] == sym1 && board[2][1] == sym1 || board[0][2] == sym1 && board[1][2] == sym1 && board[2][2] == sym1 || board[2][0] == sym1 && board[1][1] == sym1 && board[0][0] == sym1)
			{
				cout << "Player 1 wins!\n";
				gameover = true;
				return;
			}

			cout << "Player 2 enter your position between 1-9: ";
			cin >> pos2;

			if (pos2 != pos1)
			{
				switch (pos2)
				{
				case 1:
					board[0][0] = sym2;
					break;
				case 2:
					board[0][1] = sym2;
					break;
				case 3:
					board[0][2] = sym2;
					break;
				case 4:
					board[1][0] = sym2;
					break;
				case 5:
					board[1][1] = sym2;
					break;
				case 6:
					board[1][2] = sym2;
					break;
				case 7:
					board[2][0] = sym2;
					break;
				case 8:
					board[2][1] = sym2;
					break;
				case 9:
					board[2][2] = sym2;
					break;
				default:
					cout << "You didn't pick 1-9";
					break;
				}
			}
			else {
				cout << "That is already chosen, choose a different spot!\n";
			}

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					cout << board[i][j];
				}
				cout << endl;
			}
			if (board[0][0] == sym2 && board[0][1] == sym2 && board[0][2] == sym2
				|| board[1][0] == sym2 && board[1][1] == sym2 && board[1][2] == sym2 || board[2][0] == sym2 && board[2][1] == sym2 && board[2][2] == sym2 || board[0][0] == sym2 && board[1][1] == sym2 && board[2][2] == sym2 || board[0][0] == sym2 && board[1][0] == sym2 && board[2][0] == sym2 || board[0][1] == sym2 && board[1][1] == sym2 && board[2][1] == sym2 || board[0][2] == sym2 && board[1][2] == sym2 && board[2][2] == sym2 || board[2][0] == sym2 && board[1][1] == sym2 && board[0][0] == sym2)
			{
				cout << "Player 2 wins!\n";
				gameover = true;
				return;
			}
	}
}