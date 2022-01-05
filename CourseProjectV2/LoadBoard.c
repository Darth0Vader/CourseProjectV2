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
struct BoardStruct** GetSaved() {
	struct BoardStruct** board;
	FILE* file = fopen("saved.DarthVader", "r");
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
	int counter = 0, x, y, num = 0, z = 0, isConst, size = 0;
	char charac;
	int a = 0;
	while (fgets(buffer, 256, file)) {
		size = buffer[0] - '0';
		break;
	}
	board = DynamicArrayCreate(size);
	char* s;
	while (!feof(file)) {
		fscanf(file, "%d,%d,%c,%d,%d,%s", &x, &y, &charac, &num, &isConst, &s);
		board[x][y].num = num;
		board[x][y].charac = charac;
		board[x][y].isConst = isConst;
	}
	fclose(file);
	return board;
}
int SaveBoard(struct BoardStruct** board, int size) {
	printf("Enter file name(20-symbols limited):");
	char filename[20];
	scanf(" %s", &filename);
	FILE* file = fopen("saved.DarthVader", "a");
	if (file == NULL)
		file = fopen("saved.DarthVader", "w+");
	fprintf(file, "%s\n", filename);
	char buffer[10];
	FILE* save = fopen(filename, "w+");
	for (int i = 0; i < size; ++i) {
		if (i == 0)
			fprintf(save, "%d\n", size);
		for (int j = 0; j < size; ++j) {
			buffer[0] = i + '0';
			buffer[1] = ',';
			buffer[2] = j + '0';
			buffer[3] = ',';
			buffer[4] = board[i][j].charac;
			buffer[5] = ',';
			buffer[6] = board[i][j].num + '0';
			buffer[7] = ',';
			buffer[8] = board[i][j].isConst + '0';
			buffer[9] = ',';
			fprintf(save, "%s\n", buffer);
		}
	}
	fclose(save);
	return 0;
}