#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>

void Encode(char *, char *, char);
int SymbolsCounting (char *, char);
void ReplaceSymbol(char *, char, char);

int main(int argc, char *argv[]) {
	if(argc < 2) {
		printf("Please enter the source string\n");
		return 1;
	}

	char *str;
	char *startPos;

	printf("Original source string in args: %s\n",argv[1]);
	
	//Выделеяем память (длина исходной строки, которая в argv[1]) + 1 байт для '\0'
	size_t sourceStr_len = strlen(argv[1]);
	char *upperStr = malloc(sourceStr_len + 1);
	char *resultStr = malloc(sourceStr_len + 1);
	/*
	В условии if (upperStr == NULL || resultStr == NULL) возможна ситуация, когда первый вызов malloc сработал нормально 
	(upperStr != NULL), а на втором память закончилась (resultStr == NULL).
	Если просто сделать return 1, память под upperStr утечет. Чтобы не писать лишние проверки вроде
	 if (upperStr != NULL) free(upperStr);, в C используют стандартное правило: вызов free(NULL) абсолютно безопасен и ничего не делает. 
	 Поэтому можно смело вызывать free() для обоих указателей — выделившаяся память освободится, а NULL просто проигнорируется.
	*/
	if (upperStr == NULL || resultStr == NULL) {
		free(upperStr);
        free(resultStr);
		return 1;
	}

	int j=0;
	while(argv[1][j]) {
		upperStr[j] = (char)toupper((unsigned char)argv[1][j]);
		j++;
	}
	upperStr[sourceStr_len] = '\0';
	printf("String in uppercase: %s\n", upperStr);

	for (size_t i = 0; i < sourceStr_len; i++) {
		int number = SymbolsCounting(upperStr, upperStr[i]);
		resultStr[i] = (number == 1) ? '(' : ')';
	}
	resultStr[sourceStr_len] = '\0';

	printf("Original string: %s\n", argv[1]);
    printf("Encoded string:  %s\n", resultStr);

    free(upperStr);
    free(resultStr);

	return 0;
}

int SymbolsCounting (char *str, char symbol){
	int symbolCount = 0;
	while(*str) {
		if (*str == symbol)
			symbolCount++;
		str++;
	}
	return symbolCount;
}

