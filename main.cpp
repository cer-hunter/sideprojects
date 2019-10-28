#include <iostream>
#include <string>

bool victory(char board[6][7]);
void printBoard(char board[6][7]);
void setPiece(char board[6][7], char colour);

int main(void){
	char board[6][7] = { {'O','O','O','O','O','O','O'}, {'O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O'}};
	char player1 = 'R';
	char player2 = 'Y';
	std::string winner = "PlayerTwo";
	std::cout << "Player 1 has been assigned the colour Red, and player 2 has been assigned the colour Yellow\n";
	do {
		printBoard(board);
		std::cout << "Player 1's turn:\n";
		setPiece(board, player1);
		if (victory(board) == 1) {
			winner = "PlayerOne";
			break;
		}
		printBoard(board);
		std::cout << "Player 2's turn:\n";
		setPiece(board, player2);
	} while (victory(board)==0);
	printBoard(board);
	std::cout << "Congrats " << winner << " you win!";
	return 0;
}

void printBoard(char board[6][7]){
	int label = 0;
	for (label; label < 7; ++label) {
		std::cout << label + 1 << ' ';
	}
	std::cout << '\n';
	int i = 5;
	int j = 0;
	for (i; i >= 0; --i) {
		for (j; j < 7; ++j) {
			std::cout << board[i][j] << ' ';
		}
		std::cout << '\n';
		j = 0;
	}
}

void setPiece(char board[6][7], char colour) {
	std::cout << "Please select the column in which you wish to drop your piece: ";
	int j;
	std::cin >> j;
	if (j > 7) {
		std::cout << "Please select again\n";
		setPiece(board, colour);
	}
	--j;
	int i = 0;
	for (i; i < 7; ++i) {
		if (board[i][j] == 'O') {
			board[i][j] = colour;
			break;
		}
	}
	if (i == 7) {
		std::cout << "Please select again\n";
		setPiece(board, colour);
	}
}

bool victory(char board[6][7]) {
	int i = 5;
	int j = 0;
	for (i; i >= 0; --i) {
		for (j; j < 7; ++j) {
			if (board[i][j] == 'O') {
				continue;
			}
			// Checks all possible ways to win, vertical, horizontal, diagonal right, diagonal left
			else if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3]) {        
				return 1;
			}
			else if (board[i][j] == board[i - 1][j] && board[i][j] == board[i - 2][j] && board[i][j] == board[i - 3][j]) {   
				return 1;
			}
			else if (board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2] && board[i][j] == board[i - 3][j + 3]) {  
				return 1;
			}
			else if (board[i][j] == board[i - 1][j - 1] && board[i][j] == board[i - 2][j - 2] && board[i][j] == board[i - 3][j - 3]) {
				return 1;
			}
		}
		j = 0;
	}
	return 0;
}