#include <iostream>
#include<fstream>

using namespace std;

int board[6][7];
int input, player = 1;
int rows = 5;
bool game_end = false;

void handleInput(int input) {
	if (rows >= 0) {
		if (board[rows][input] != 0) {
			rows--;
			handleInput(input);
		}
		else {
			board[rows][input] = player;
			rows = 5;
		}
	}
	else {
		cout << "wrong input!";
		player = player == 1 ? 2 : 1;
		rows = 5;
	}
}

void whoWins(string x1, string x2) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			if (board[i][j] == player && board[i][j - 1] == player && board[i][j - 2] == player && board[i][j - 3] == player) {
				game_end = true;
				if (player == 1) {
					cout << x1 << " Wins!" << endl;
				}
				else {
					cout << x2 << " Wins!" << endl;
				}
			}
			else if (board[i][j] == player && board[i - 1][j] == player && board[i - 2][j] == player && board[i - 3][j] == player) {
				game_end = true;
				if (player == 1) {
					cout << x1 << " Wins!" << endl;
				}
				else {
					cout << x2 << " Wins!" << endl;
				}
			}
			else if (board[i][j] == player && board[i - 1][j - 1] == player && board[i - 2][j - 2] == player && board[i - 3][j - 3] == player) {
				game_end = true;
				if (player == 1) {
					cout << x1 << " Wins!" << endl;
				}
				else {
					cout << x2 << " Wins!" << endl;
				}
			}
			else if (board[i][j] == player && board[i - 1][j + 1] == player && board[i - 2][j + 2] == player && board[i - 3][j + 3] == player) {
				game_end = true;
				if (player == 1) {
					cout << x1 << " Wins!" << endl;
				}
				else {
					cout << x2 << " Wins!" << endl;
				}
			}
		}
	}
}

bool is2DArrayFull(int arr[][3], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (arr[i][j] == 0) {
				return false; // If any element is not assigned a value, the array is not full
			}
		}
	}
	return true; // All elements have been assigned a value, the array is full
}

void draw() {
	system("cls"); // to clear screen
	for (int j = 0; j < 7; j++) {
		cout << "--" << j + 1 << "--";
	}
	cout << endl;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			if (board[i][j] == 0) {
				cout << "|   |";
			}
			else if (board[i][j] == 1) {
				cout << "| X |";
			}
			else if (board[i][j] == 2) {
				cout << "| O |";
			}

		}
		cout << endl;
	}
	for (int j = 0; j < 7; j++) {
		cout << "=====";
	}
	cout << endl;
}

int main()
{
	string x1, x2;
	ofstream outfile2;
	outfile2.open("player1.txt");
	ofstream outfile1;
	outfile1.open("player2.txt");
	cout << "player 1 enter your name " << endl;
	cin >> x1;
	outfile2 << x1; 
	cout << "player 2 enter your name " << endl;
	cin >> x2;
	outfile1 << x2;
	outfile1.close();
	outfile2.close();

	draw();
	while (!game_end) {
		if (player == 1) {
			cout << x1 << ": ";
		}
		else {
			cout << x2 << ": ";
		}

		while (true) {
			cin >> input;
			if (input >= 1 && input <= 7)
				break;
			else
				cout << "Invalid Input ";
		}

		handleInput(input - 1);
		draw();
		whoWins(x1, x2);
		player = player == 1 ? 2 : 1;
	}
}