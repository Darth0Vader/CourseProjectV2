#define _CRT_SECURE_NO_WARTNINGS
#include "stdio.h";
#include "BoardStruct.h";
void PrintBoard(struct BoardStruct** board, int size)
{
	//system("cls");
	printf(" ");
	for (int i = 0; i < size; i++) {
		printf("   %d ", i + 1);
	}
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("%d", i + 1);
		for (int z = 0; z < size; z++) {
			switch (board[i][z].isConst) {
			case 1: {
				printf("| \033[0;34m%c\033[0m", board[i][z].charac);
				if (board[i][z].isCorrect == 1) {
					printf("\033[0;31m");
				}
				printf("%c\033[0m ", board[i][z].num == 0 ? ' ' : board[i][z].num + '0');
			}
				  break;
			case 2: {
				printf("|");
				if (board[i][z].isCorrect == 1) {
					printf("\033[0;31m");
				}
				printf(" %c\033[0;34m%c\033[0m ", board[i][z].charac,
					board[i][z].num == 0 ? ' ' : board[i][z].num + '0');
			}
				  break;
			case 3: {
				printf("| \033[0;34m%c%c\033[0m ", board[i][z].charac,
					board[i][z].num == 0 ? ' ' : board[i][z].num + '0');
			}
				  break;
			default: {
				switch (board[i][z].isCorrect) {
				case 1: {
					printf("| \033[0;31m%c%c\033[0m ", board[i][z].charac,
						board[i][z].num == 0 ? ' ' : board[i][z].num + '0');
				}
					  break;
				default: {
					printf("| %c%c ", board[i][z].charac,
						board[i][z].num == 0 ? ' ' : board[i][z].num + '0');
				}
					   break;
				}
				break;
			}
			}
		}
		printf("|\n");
		for (int z = 0; z < size; z++) {
			printf("------");
		}
		printf("\n");
	}
}