#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h";
#include "BoardStruct.h";
#include "malloc.h";
void DynamicArray(int size, struct BoardStruct** board)
{
	board = (struct BoardStruct**)malloc(size * sizeof(struct BoardStruct));
	for (int i = 0; i < size; ++i) {
		board[i] = (struct BoardStruct*)malloc(size * sizeof(struct BoardStruct));
	}
	return board;
}