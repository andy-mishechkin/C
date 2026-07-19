#include <stdio.h>
#include <string.h>

void Encode(char *, char *, char);
int SymbolsCounting (char *, char);
void ReplaceSymbol(char *, char, char);

void main(int argc, char *argv[]) {
	if(argc < 2) {
		printf("Please enter the source string\n");
		exit(1);
	}

	char *str;
	char *startPos;
	for(int i=1;i<argc;i++) {
		printf("Source string: %s\n",argv[i]);

		int j=0;
		while(argv[i][j]) {
			argv[i][j] = toupper(argv[i][j]);
			j++;
		}
		printf("Target string: %s\n", argv[i]);
		str = startPos = argv[i];
		while(*str) {
			Encode(startPos, str, *str);
			str++;
		}
		printf("Target string after replacing: %s\n", argv[i]);
	}
}

void Encode (char *startPos, char *str, char symbol) {
	int symbolCount = 0;
	char *currentPos;

	if (str > startPos) {
		currentPos = startPos;
		while(currentPos < str) {
			if(*currentPos == *str)
				return;
			else
				symbolCount = SymbolsCounting (str, symbol);
			currentPos++;
		}
	}
	else
		symbolCount = SymbolsCounting(str, symbol);

	printf("Sybol: %c, Count: %d\n", symbol, symbolCount);

	if (symbolCount == 1)
		ReplaceSymbol(startPos, *str, '(');
	else
		ReplaceSymbol(startPos, *str, ')');
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

void ReplaceSymbol(char *str, char symbol, char replacer) {
	while(*str) {
		if (*str == symbol)
			*str = replacer;
		str++;
	}
}
