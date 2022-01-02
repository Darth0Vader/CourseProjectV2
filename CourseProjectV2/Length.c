#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h";
int Length(char* string)
{
	int lenght = 0;
	for (int i = 0; string != '\0'; i++)
	{
		++lenght;
	}
	return lenght;
}