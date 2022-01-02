#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h";
#include "BoardStruct.h";
int main()
{
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
			struct BoardStruct** board = LoadBoard(choose[--choise], &size, board);
			PrintBoard(board, size);
		}break;
		case 2: {

		}break;
		case 3: {

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