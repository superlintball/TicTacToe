/*
 * Author: Raveen Karnik
 * Date: 9-21-17
 * This program creates an interactive command line version of Tic-Tac-Toe
 */

#include <iostream>

using namespace std;

void clearBoard(int board[][3], int B);
void printBoard(int board[3][3]);
bool checkValid(char input[5]);
bool checkTie(int board[3][3], int B);
bool checkWin(int board[3][3], int player);

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

	//clear board and print it
	clearBoard(board, B);
	printBoard(board);

	while(stillPlaying)
	{
		//prompt the user with directions in how to play
		cout << "Enter a row letter followed by a column number." << endl;
		cout << "It is " << userTurn << "'s turn." << endl;
		cin >> input;

		//make sure the input was a valid spot on the board
		if(checkValid(input))
		{
			//make sure the input was a blank spot
			if(board[input[0]-'a'][input[1]-'1'] == B)
			{
				//update board and print it
				board[input[0]-'a'][input[1]-'1'] = turn;
				printBoard(board);
				
				//variable to keep track of whether or not the game has ended
				bool gameEnd = false;

				//check if the game just ended
				if (checkWin(board, turn))
				{
					//output who just won and increase that player's wins
					cout << userTurn << " just won!" << endl;
					if(turn == X)
					{
						xWins++;
					} else
					{
						oWins++;
					}
					gameEnd = true;

				} else if (checkTie(board, B))
				{
					cout << "Looks like it's a tie!" << endl;
					gameEnd = true;
				}
				
				//if the game just ended, either by tie or win
				if(gameEnd)
				{
					//output wins and ask if they want to play again
					cout << "X wins:" << xWins << " O wins:" << oWins << endl;
					cout << "Play Again? (y/n)" << endl;
					//keep asking until the answer is valid
					char keepPlaying = 'w';
					cin >> keepPlaying;
					while (!(keepPlaying == 'y' || keepPlaying == 'n' || 
								keepPlaying  == 'Y' || keepPlaying == 'N'))
					{
						cout << "I couldn't understand that. Play again? (y/n)" << endl;
						cin >> keepPlaying;
					}

					//signal program to end if no; reset board if yes
					if(keepPlaying == 'n' || keepPlaying == 'N')
					{
						stillPlaying = false;
					} else
					{
						clearBoard(board, B);
						printBoard(board);
					}
				}

				//switch turn regardless of game end
				if (turn == X)
				{
					turn = O;
					userTurn = 'O';
				} else if (turn == O)
				{
					turn = X;
					userTurn = 'X';
				}
			} else
			{
				cout << "That spot is already taken. Choose another one." << endl;
			}
		}
	}

	return 0;
}

//set all spots to blank
void clearBoard (int board[][3], int B)
{
	for(int row = 0; row < 3; row++)
		for(int col = 0; col < 3; col++)
			board[row][col] = B;
}

//function to print board to users
void printBoard(int board[3][3])
{
	cout << "\t1\t2\t3" << endl;
	for(int row = 0; row < 3; row++)
	{
		cout << (char)('a' + row) << '\t';
		for(int col = 0; col < 3; col++)
		{
			if(board[row][col] == 'X')
			{
				cout << "X";
			} else if(board[row][col] == 'O')
			{
				cout << "O";
			}
			cout << "\t";
		}
		cout << endl;
	}

}

//check if user input is a valid board space
bool checkValid(char input[5])
{
	if(input[2] != '\0')
	{
		cout << "The input was too long. I couldn't understand that." << endl;
		return false;
	} else if(input[0] != 'a' && input[0] != 'b' && input[0] != 'c')
	{
		cout << "You did not enter a valid row letter" << endl;
		return false;
	} else if(input[1] != '1' && input[1] != '2' && input[1] != '3')
	{
		cout << "You did not enter a valid column number" << endl;
		return false;
	} else
	{
		return true;
	}
}

//check to see if any spaces are blank
bool checkTie(int board[3][3], int B)
{
	for(int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (board[row][col] == B)
				return false;
	return true;
}

//code from my old Java TicTacToe project, adapted to C++
//checks if the player has won by checking all win conditions
bool checkWin(int board[3][3], int player)
{
	//check diagonals
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
	{
		return true;
	} else if (board[2][0] == player && board[1][1] == player && board[0][2] == player)
	{
		return true;
	}

	//check columns
	for (int col = 0; col < 3; col++)
		if (board[0][col] == player && board[1][col] == player && board[2][col] == player)
			return true;

	//check rows
	for (int row = 0; row < 3; row++)
		if (board[row][0] == player && board[row][1] == player && board[row][2] == player)
			return true;

	return false;
}
	
