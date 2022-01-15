#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h";
#include "BoardStruct.h";
int GetRecords() {
    char buffer[256];
    int i = 0;
    FILE* file = fopen("recordList.DarthVader", "r");
    while (fgets(buffer, 256, file)) {
        printf("%d)%s\n", ++i, buffer);
    }
    return 0;
}
int WriteRecord() {
    printf("Enter your name sith(20-symbol limited):");
    char name[20];
    scanf("%s", &name);
    FILE* file;
    file = fopen("recordList.DarthVader", "a+");
    if (file == NULL) {
        file = fopen("recordList.DarthVader", "w+");
    }
    fprintf(file, "%s\n", name);
    fclose(file);
    return 0;
}