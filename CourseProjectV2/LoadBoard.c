#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h";
#include "BoardStruct.h";
#include "malloc.h";
#include "string.h";
struct BoardStruct** LoadBoard(char* name, int* size)
{
	FILE* file;
	char fname[9];
	memcpy(fname, name, 9);
	file = fopen(fname, "r");
	fscanf(file, "%d", size);
	struct BoardStruct** board = (struct BoardStruct**)malloc(*size, sizeof(struct BoardStruct));
	for (int i = 0; i < *size; ++i) {
		board[i] = (struct BoardStruct*)malloc(*size, sizeof(struct BoardStruct));
	}
	int x, y, num, isConst;
	char charac;
	while (!feof(file))
	{
		fscanf(file, "%d,%d,%c,%d,%d", &x, &y, &charac, &num, &isConst);
		board[x][y].num = num;
		board[x][y].charac = charac;
		board[x][y].isConst = isConst;
	}
	return board;
}