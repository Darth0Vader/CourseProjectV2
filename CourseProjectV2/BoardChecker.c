#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h";
#include "BoardStruct.h";
int BoardChecker(struct BoardStruct** board, int size)
{
	for (int i = 0; i < size; i++) {
		for (int z = 0; z < size; z++) {
			for (int g = z; g < size - 1; g++) {
				if ((board[i][z].charac == board[i][g + 1].charac ||
					board[i][z].num == board[i][g + 1].num) &&
					board[i][z].charac != ' ' &&
					board[i][z].num != 0) {
					board[i][z].isCorrect = 1;
					board[i][g + 1].isCorrect = 1;
				}
				if ((board[z][i].charac == board[g + 1][i].charac ||
					board[z][i].num == board[g + 1][i].num) &&
					board[i][z].charac != ' ' &&
					board[i][z].num != 0) {
					board[z][i].isCorrect = 1;
					board[g + 1][i].isCorrect = 1;
				}
			}
		}
	}
	return 0;
}
int GameOver(struct BoardStruct** board, int size) {
	int counter = 0, underCounter = 0;
	for (int i = 0; i < size; i++) {
		for (int z = 0; z < size; z++) {
			if (board[i][z].isCorrect > 0)
				counter++;
			if (board[i][z].charac == ' '
				|| board[i][z].num == 0)
				++underCounter;
		}
	}
	if (counter == 0 && underCounter == 0)
		return 0;
	return 1;
}