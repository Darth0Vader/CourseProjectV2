#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h";
#include "BoardStruct.h";
#include "locale.h";
struct BoardStruct** LoadBoard(char* name, int* size);
int DefaultCells(struct BoardStruct**, int);
int BoardChecker(struct BoardStruct**, int);
int GameOver(struct BoardStruct**, int);
int SaveBoard(struct BoardStruct**, int);
int GetRecords();
int WriteRecord();
int PrintBoard(struct BoardStruct**, int);
int StartGame(struct BoardStruct** board, int size);
struct BoardStruct** GetSaved(int* size);
int main()
{
	setlocale(LC_ALL, "En-en");
	printf("Welcome to game!\n");
	while (1 == 1)
	{
		printf("1-start new game\n2-load saved game\n3-load record list\n5-exit:\n");
		int choise = 0;
		scanf("%d", &choise);
		switch (choise)
		{
		case 1: {
			printf("Choose level padavan:\n");
			printf("1-noob\n2-boop\n3-jedi\n4-sith:");
			scanf("%d", &choise);
			char noob[] = "noob.txt\0";
			char boop[] = "boop.txt\0";
			char jedi[] = "jedi.txt\0";
			char sith[] = "sith.txt\0";
			char* choose[4];
			choose[0] = noob;
			choose[1] = boop;
			choose[2] = jedi;
			choose[3] = sith;
			int size = 0;
			struct BoardStruct** board = LoadBoard(choose[--choise], &size);
			return StartGame(board, size);
		}break;
		case 2: {
			int size = 0;
			struct BoardStruct** board = GetSaved(&size);
			if (board == NULL)
				continue;
			return StartGame(board, size);
		}break;
		case 3: {
			GetRecords();
		}break;
		case 4: {

		}break;
		case 5: {
			return 0;
		}
		}
	}
	return 0;
}
int StartGame(struct BoardStruct** board, int size)
{
	BoardChecker(board, size);
	while (1 == 1)
	{
		int x = 0, y = 0, num = 0;
		char charac;
		while (1 == 1) {
			PrintBoard(board, size);
			printf("Enter y or -1 to quit\n -2 for save game:");
			scanf("%d", &x);
			if (x == -1)
				return 1;
			if (x == -2) {
				SaveBoard(board, size);
				return 1;
			}
			printf("Enter x:");
			scanf("%d", &y);
			printf("Enter value (A1):");
			scanf(" %c%d", &charac, &num);
			charac = toupper(charac);
			x--;
			y--;
			if (board[x][y].isConst == 2) {
				board[x][y].charac = charac;
			}
			else if (board[x][y].isConst == 1) {
				board[x][y].num = num;
			}
			else if (board[x][y].isConst != 3) {
				board[x][y].charac = charac;
				board[x][y].num = num;
			}
			DefaultCells(board, size);
			BoardChecker(board, size);
			if (!GameOver(board, size)) {
				PrintBoard(board, size);
				printf("Congratulations!!!\n");
				return WriteRecord();
			}
		}
	}
}