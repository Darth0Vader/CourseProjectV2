#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h";
#include "BoardStruct.h";
#include "malloc.h";
#include "string.h";
struct BoardStruct** DynamicArrayCreate(int*);
struct BoardStruct** LoadBoard(char* name, int* size)
{
	FILE* file;
	char fname[9];
	memcpy(fname, name, 9);
	file = fopen(fname, "r");
	fscanf(file, "%d", size);
	struct BoardStruct** board = DynamicArrayCreate(size);
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
struct BoardStruct** GetSaved(int* size) {
	struct BoardStruct** board;
	FILE* file = fopen("saved.DarthVader", "r");
	if (file != NULL)
	{
		int i = 0;
		char buffer[256];
		char fileName[20] = "test";
		while (fgets(buffer, 256, file)) {
			printf("%d)%s\n", ++i, buffer);
		}
		printf("Enter name:");
		scanf(" %s", &fileName);
		fclose(file);
		file = fopen(fileName, "r");
		int counter = 0, x, y, num = 0, z = 0, isConst;
		char charac;
		int a = 0;
		fscanf(file, "%d", size);
		board = DynamicArrayCreate(size);
		while (!feof(file)) {
			fscanf(file, "%d,%d,%c,%d,%d,", &x, &y, &charac, &num, &isConst);
			board[x][y].num = num;
			board[x][y].charac = charac;
			board[x][y].isConst = isConst;
		}
		fclose(file);
		return board;
	}
	printf("No saved boards were found!\n");
	return NULL;
}
int SaveBoard(struct BoardStruct** board, int size) {
	printf("Enter file name(20-symbols limited):");
	char filename[20];
	scanf("%s", &filename);
	FILE* file = fopen("saved.DarthVader", "a");
	if (file == NULL)
		file = fopen("saved.DarthVader", "w+");
	fprintf(file, "%s\n", filename);
	fclose(file);
	FILE* save = fopen(filename, "w+");
	for (int i = 0; i < size; ++i) {
		if (i == 0)
			fprintf(save, "%d\n", size);
		for (int j = 0; j < size; ++j) {
			fprintf(save, "%d,%d,%c,%d,%d,\n", i, j, board[i][j].charac, board[i][j].num, board[i][j].isConst);
		}
	}
	fclose(save);
	return 0;
}