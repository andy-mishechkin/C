/*
Write a method that takes an array of consecutive (increasing) letters as input and that returns the missing letter in the array.
You will always get an valid array. And it will be always exactly one letter be missing. The length of the array will always be at least 2.
The array will always contain letters in only one case.

['a','b','c','d','f'] -> 'e'
['O','Q','R','S'] -> 'P'
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h> 

/*
В языке C каждый символ (char) — это просто маленькое целое число (например, 'a' = 97, 'b' = 98, 'c' = 99). 
Поскольку буквы латинского алфавита идут в таблице строго по порядку, с ними можно делать обычную арифметику.
Цикл в функции findMissingLetter идет до length - 1 (до предпоследнего элемента). 
Это нужно, чтобы на последнем шаге сравнить предпоследнюю букву с последней (array[i + 1]) и не выйти за пределы массива.
Если буквы идут подряд (например, 'a' и 'b'), их коды отличаются ровно на единицу (98 - 97 == 1).
Если разница не равна 1 (например, после 'd' идет 'f', то есть 102 - 100 == 2), значит, между ними пропущена буква.
*/
char findMissingLetter(const char array[], size_t length) {
	for (size_t i = 0; i < length - 1; i++) {
		if (array[i + 1] - array[i] != 1)
			return array[i] + 1;
	}
	return '\0';
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
		fprintf(stderr, "Please enter the source string\n");
		return 1;
	}

	size_t len = strlen(argv[1]);
	if (len < 2) {
        fprintf(stderr, "Array length must be at least 2\n");
        return 1;
    }

	char missing = findMissingLetter(argv[1], len);
	if (missing != '\0') {
        printf("Missing letter: %c\n", missing);
    } 
	else {
        printf("No missing letters found\n");
    }
    return 0;
}