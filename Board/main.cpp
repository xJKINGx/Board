#include <iostream>
#include <conio.h>

const int row = 10;
const int col = 10;
char boardGrid[row][col] = {};
int playerXPos{};
int playerYPos{};

void drawBoard();

int main() {
	//This for loop initializes the board
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			boardGrid[i][j] = '0';
		}
	}
	// X is the player
	boardGrid[playerXPos][playerYPos] = 'X';
	boardGrid[9][9] = 'G';
	boardGrid[5][5] = '/';
	boardGrid[3][3] = '\\';

	bool game_loop = true;

	while (game_loop) {
		
		drawBoard();

		boardGrid[playerXPos][playerYPos] = '0';
		char ch = _getch();

		

		// Col = Y axis
		// Row = X axis
		// We need to find X every time we want to move

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (boardGrid[i][j] == 'X') {
					playerXPos = j;
					playerYPos = i;
					break;
				}
			}
		}

		switch (ch) {
		case 'w':
			// If we move up, col will be subtracted by 1
			if ((playerXPos - 1) >= 0) {
				playerXPos--;
			}
			else {
				break;
			}
			break;
		case 'a':
			// If we move left, row will be subtracted by 1
			if ((playerYPos - 1) >= 0) {
				playerYPos--;
			}
			else {
				break;
			}

			break;
		case 's':
			// If we move down, col will be added by 1
			if ((playerXPos + 1) < 10) {
				playerXPos++;
			}
			else {
				break;
			}
			break;
		case 'd':
			// If we move right, row will be added by 1
			if ((playerYPos + 1) < 10) {
				playerYPos++;
			}
			else {
				break;
			}
		default:
			break;
		}

		if (boardGrid[playerXPos][playerYPos] == 'G') {
			exit(0);
		}
		else if (boardGrid[playerXPos][playerYPos] == '/') {
			playerXPos++;
		}
		else if (boardGrid[playerXPos][playerYPos] == '\\') {
			playerXPos--;
		}

		boardGrid[playerXPos][playerYPos] = 'X';
	}
}

void drawBoard() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << boardGrid[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "---------------------" << std::endl;
}

