#define _CRT_SECURE_NO_WARNIINGS
#include "stdio.h";
#include "malloc.h";
#include "BoardStruct.h";
struct BoardStruct** DynamicArrayCreate(int* msize)
{
	int size = *msize;
	struct BoardStruct** board = (struct BoardStruct**)malloc(size, sizeof(struct BoardStruct));
	for (int i = 0; i < size; ++i) {
		board[i] = (struct BoardStruct*)malloc(size, sizeof(struct BoardStruct));
	}
	MakeDefault(board, size);
	return board;
}
int MakeDefault(struct BoardStruct** board, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int a = 0; a < size; a++)
		{
			board[i][a].charac = ' ';
			board[i][a].isConst = 0;
			board[i][a].isCorrect = 0;
			board[i][a].num = 0;

		}
	}
	return 0;
}
int DefaultCells(struct BoardStruct** board, int size)
{
	for (int i = 0; i < size; i++) {
		for (int z = 0; z < size; z++) {
			board[i][z].isCorrect = 0;
		}
	}
	return 0;
}