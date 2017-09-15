/*
 * Author: Raveen Karnik
 * Date: 9-15-17
 * This program creates an interactive command line version of Tic-Tac-Toe
 */

#include <iostream>

using namespace std;

void printBoard(int board[3][3]);
bool checkValid(char input[5]);

//main code block
int main()
{
	//initialize board
	int board[3][3];

	//board possibilities (B stands for blank)
	const int B = 'B';
	const int X = 'X';
	const int O = 'O';

	//player wins
	int xWins = 0;
	int oWins = 0;

	//turn counter
	int turn = X;
	char userTurn = 'X';

	//user input
	char input[5];

	//keep track of whether or not they're playing
	bool stillPlaying = true;

	//set all values of board to blank
	for(int row = 0; row < 3; row++)
	{
		for(int col = 0; col < 3; col++)
		{
			board[row][col] = B;
		}
	}

	while(stillPlaying)
	{
		//prompt the user with directions in how to play
		cout << "Enter a row letter followed by a column number." << endl;
		cout << "It is " << userTurn << "'s turn." << endl;

		cin >> input;
		checkValid(input);
		stillPlaying = false;
	}

	return 0;
}

//function to print board to users
void printBoard(int board[3][3])
{
	cout << "\t1\t2\t3" << endl;
	for(int row = 0; row < 3; row++)
	{
		cout << static_cast<char>('a' + row) << '\t';
		for(int col = 0; col < 3; col++)
		{
			if(board[row][col] == 'X')
			{
				cout << "X";
			}
			else if(board[row][col] == 'O')
			{
				cout << "O";
			}
			cout << "\t";
		}
		cout << endl;
	}

}

bool checkValid(char input[5])
{
	if(input[2] != '\0')
	{
		cout << "The input was too long. I couldn't understand that." << endl;
		return false;
	}
	else if(input[0] != 'a' && input[0] != 'b' && input[0] != 'c')
	{
		cout << "You did not enter a valid row letter" << endl;
		return false;
	}
	else if(input[1] != '1' && input[1] != '2' && input[1] != '3')
	{
		cout << "You did not enter a valid column number" << endl;
		return false;
	}
	else
	{
		return true;
	}
}
