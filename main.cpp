
#include <iostream>
#include <fstream>
#include <math.h>
#include <Windows.h>
#include <limits>
#include <limits.h>
#include <vector>
#include <math.h>
using namespace std;
void nextTurn(string board[3][3]);
int minimax(string board[3][3], int depth, bool isMaximizing);
string checkWinner(string board[3][3]);
string Move(string board[3][3]);
void ask(string Winner, string board[3][3]);
string ai = "X";
string Player = "O";
int play = 2;
int main()
{
	string anwser;
	string board[3][3] = {
		{"1", "2", "3"},
		{"4", "5", "6"},
		{"7", "8", "9"}
	};
	string a = checkWinner(board);
	while (a == "nothing")
	{
		a = checkWinner(board);
		Move(board);
		Sleep(100);
		a = checkWinner(board);
		if (a != "nothing")
		{
			break; 
		}
		nextTurn(board);
		Sleep(100);
		a = checkWinner(board);
		if (a != "nothing")
		{
			break;
		}
	}
	ask(a, board);




	return -1;
}
string Move(string board[3][3])
{
	system("cls");

	for (int i = 0; i < 3; i++)
	{
		cout << board[i][0] << "   |   " << board[i][1] << "   |   " << board[i][2] << endl;

	}
	int moe;
	cin >> moe;

	switch (moe)
	{
	case 1: if ((board[0][0] != ai)&&(board[0][0] != Player)) {
		board[0][0] = "O"; 
		break;
	}
		  else
	{
		cout << "Already taken, please choose another one!" << endl;
		Sleep(1000);
		Move(board);
		break;
	}
	
	case 2: if ((board[0][1] != ai) && (board[0][1] != Player)) {
		board[0][1] = "O";
		break;
	}
		  else
	{
		cout << "Already taken, please choose another one!" << endl;
		Sleep(1000);
		Move(board);
		break;
	}
	case 3:if ((board[0][2] != ai) && (board[0][2] != Player)) {
		board[0][2] = "O";
		break;
	}
		  else
	{
		cout << "Already taken, please choose another one!" << endl;
		Sleep(1000);
		Move(board);
		break;
	}
	case 4: if ((board[1][0] != ai) && (board[1][0] != Player)) {
		board[1][0] = "O";
		break;
	}
		  else
	{
		cout << "Already taken, please choose another one!" << endl;
		Sleep(1000);
		Move(board);
		break;
	}
	case 5:if ((board[1][1] != ai) && (board[1][1] != Player)) {
		board[1][1] = "O";
		break;
	}
		  else
	{
		cout << "Already taken, please choose another one!" << endl;
		Sleep(1000);
		Move(board);
		break;
	}
	case 6:if ((board[1][2] != ai) && (board[1][2] != Player)) {
		board[1][2] = "O";
		break;
	}
		  else
	{
		cout << "Already taken, please choose another one!" << endl;
		Sleep(1000);
		Move(board);
		break;
	}
	case 7: if ((board[2][0] != ai) && (board[2][0] != Player)) {
		board[2][0] = "O";
		break;
	}
		  else
	{
		cout << "Already taken, please choose another one!" << endl;
		Sleep(1000);
		Move(board);
		break;
	}
	case 8: if ((board[2][1] != ai) && (board[2][1] != Player)) {
		board[2][1] = "O";
		break;
	}
		  else
	{
		cout << "Already taken, please choose another one!" << endl;
		Sleep(1000);
		Move(board);
		break;
	}
	case 9: if ((board[2][2] != ai) && (board[2][2] != Player)) {
		board[2][2] = "O";
		break;
	}
		  else
	{
		cout << "Already taken, please choose another one!" << endl;
		Sleep(1000);
		Move(board);
		break;
	}
	default: break;
	}


	return "aua";
}
string checkWinner(string board[3][3]) {

	for (int i = 0; i < 3; i++)
	{

		if (board[i][0] == Player && board[i][1] == Player && board[i][2] == Player) {
			return Player;
		}
		else if (board[i][0] == ai && board[i][1] == ai && board[i][2] == ai) {
			return ai;
		}
		else if (board[0][i] == Player && board[1][i] == Player && board[2][i] == Player) {
			return Player;
		}
		else if (board[0][i] == ai && board[1][i] == ai && board[2][i] == ai) {
			return ai;
		}
		else if (board[0][0] == Player && board[1][1] == Player && board[2][2] == Player)
		{
			return Player;
		}
		else if (board[0][0] == ai && board[1][1] == ai && board[2][2] == ai)
		{
			return ai;
		}
		else if (board[0][2] == Player && board[1][1] == Player && board[2][0] == Player)
		{
			return Player;
		}
		else if (board[0][2] == ai && board[1][1] == ai && board[2][0] == ai)
		{
			return ai;
		}
		else if ((board[0][0] == ai || board[0][0] == Player) && (board[0][1] == Player || board[0][1] == ai))
		{
			if ((board[0][2] == ai || board[0][2] == Player) && (board[1][0] == Player || board[1][0] == ai))
			{
				if ((board[1][1] == ai || board[1][1] == Player) && (board[1][2] == Player || board[1][2] == ai))
				{
					if ((board[2][0] == ai || board[2][0] == Player) && (board[2][1] == Player || board[2][1] == ai))
					{
						if ((board[2][2] == ai || board[2][2] == Player))
						{
							return "tie";
						}
					}
				}
			}

		}
	}
	return "nothing";

}

int minimax(string board[3][3], int depth, bool isMaximizing)
{
	string result = checkWinner(board);
	if (result != "nothing")
	{
		if (result == ai)
		{

			return 1;
		}

		else if (result == Player)
		{

			return -1;

		}
		else {
			return 0;

		}
	}
	if (isMaximizing)
	{
		int bestScore = -80000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				string temp = board[i][j];


				if (board[i][j] != ai && board[i][j] != Player)
				{
					board[i][j] = ai;
					int score = minimax(board, depth + 1, false);
					board[i][j] = temp;
					bestScore = max(bestScore, score);
				}
			}
		}
		return bestScore;
	}
	else
	{
		int bestScore = 80000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				string temp = board[i][j];


				if (board[i][j] != ai && board[i][j] != Player)
				{
					board[i][j] = Player;
					int score = minimax(board, depth + 1, true);
					board[i][j] = temp;
					bestScore = min(bestScore, score);
				}
			}
		}
		return bestScore;
	}



}
void nextTurn(string board[3][3])
{


	int move[5] = { 0, 0, 0, 0, 0 };
	int bestScore = -80000;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			string temp = board[i][j];


			if ((board[i][j] != ai) && (board[i][j] != Player))
			{
				board[i][j] = ai;
				int score = minimax(board, 0, false);
				board[i][j] = temp;
				if (score > bestScore)
				{
					bestScore = score;
					move[1] = i;
					move[2] = j;
				}
			}
		}
	}
	board[move[1]][move[2]] = ai;

}
void ask(string Winner, string board[3][3]) {
	string ab = checkWinner(board);
	string anwser;
	string newBoard[3][3] = {
		{"1", "2", "3"},
		{"4", "5", "6"},
		{"7", "8", "9"}
	};
	
	if (Winner == ai)
	{
		cout << ai << " has won" << endl;

	}
	else if  (Winner == Player)
	{
		cout << Player << " has won" << endl;
	}
	else {
		cout << "tie" << endl;
	}
	cout << "Wanna play again? (y/n)";
	cin >> anwser;

	if (anwser == "y")
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				board[i][j] = newBoard[i][j];
			}
		}
 
		

		if (play % 2 == 0)
		{
			ab = checkWinner(board);
			while (ab == "nothing")
			{
				ab = checkWinner(board);
				if (ab != "nothing")
				{
					break;
				}
				nextTurn(board);
				ab = checkWinner(board);
				if (ab != "nothing")
				{
					break; 
				}
				Move(board);
			}
			play++;
			ask(ab, board);
		}
		else
		{
			ab = checkWinner(board);
			while (ab == "nothing")
			{
				ab = checkWinner(board);
				if (ab != "nothing")
				{
					break;
				}
				Move(board); 
				ab = checkWinner(board);
				if (ab != "nothing")
				{
					break;
				}
				nextTurn(board);
			}
			play++; 
			ask(ab, board);
		}

	}
	else
	{
		cout << "Thanks for playing " << endl; 
	}

}



