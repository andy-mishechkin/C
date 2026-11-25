/*
Given n, take the sum of the digits of n. If that value has more than one digit, 
continue reducing in this way until a single-digit number is produced. The input will be a non-negative integer.

Examples:
16  -->  1 + 6 = 7
942  -->  9 + 4 + 2 = 15  -->  1 + 5 = 6
132189  -->  1 + 3 + 2 + 1 + 8 + 9 = 24  -->  2 + 4 = 6
493193  -->  4 + 9 + 3 + 1 + 9 + 3 = 29  -->  2 + 9 = 11  -->  1 + 1 = 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void digital_root(int n) {
	/*
	int count = (num == 0) ? 1 : 0;
	• Если num равно 0, счетчик count сразу становится 1 (ведь в числе 0 одна цифра, а цикл while (temp > 0) для нуля вообще не запустится).
	• Для любого другого числа счетчик начинается с 0
	Цикл работает, пока число больше нуля. Внутри него происходят два действия:
	• temp /= 10; — целочисленное деление на 10. В языке C при делении целых чисел дробная часть просто отбрасывается. 
	Так мы «отрезаем» по одной цифре справа.
	Как это работает на примере числа 176
	Шаг цикла	Действие temp /= 10	Значение temp	Значение count
	До цикла		—					176					0
	1-й проход	176 / 10 = 17			17					1
	2-й проход	17 / 10 = 1				1					2
	3-й проход	1 / 10 = 0				0					3
	*/
	int temp = n;
	int count = (n == 0) ? 1 : 0;
	while (temp > 0) {
		temp /= 10;
		count++;
	}
	int digits[count];

	temp = n;
	int sumOfArr=0;
    for (int i = count - 1; i >= 0; i--) {
		/*
		1. digits[i] = temp % 10;
		Оператор % вычисляет остаток от деления на 10 — это всегда самая правая (последняя) цифра числа. 
		Мы кладем ее в текущую ячейку массива с конца.
		2. temp /= 10;
		Делим число на 10 нацело, чтобы «отрезать» только что записанную цифру и перейти к следующей.
		Как это работает на примере 176 (count = 3)
		Шаг		Индекс i		temp до шага		Остаток temp % 10		Запись в массив			temp после /= 10
		1	  	2				176					6						digits[2] = 6			17
		2		1				17					7						digits[1] = 7			1
		3		0				1					1						digits[0] = 1			0
		*/
        digits[i] = temp % 10; 
        temp /= 10; 
		sumOfArr += digits[i];         
    }
	printf("Sum of current array: %d\n", sumOfArr);

	if (sumOfArr > 9) 
		digital_root(sumOfArr);
	else
		printf("Final sum result: %d\n", sumOfArr);
}

int main(int argc, char *argv[]) {
	if(argc < 2) {
		fprintf(stderr, "Please enter the source string\n");
		return 1;
	}
	
	/*
	Как работает безопасное преобразование строки в число.
	В языке C любая строка в памяти заканчивается невидимым нулевым символом '\0'. 
	Например, строка "176" на самом деле хранится так: ['1', '7', '6', '\0'].
	Когда strtol(str, &endptr, 10) читает строку, она сдвигает указатель endptr на первый символ, 
	который не смогла превратить в цифру.
	Сценарий А: В строке были только цифры ("176")
	strtol прочитала '1', '7', '6' и уперлась в конец строки. 
	В этом случае endptr указывает на '\0'. Условие *endptr == '\0' истинно — конвертация прошла чисто.
	Сценарий Б: В строке есть мусор ("176abc")
	strtol прочитает 176, споткнется о букву 'a' и остановится. В переменной num окажется 176, но *endptr будет равен 'a', а не '\0'. 
	Сработает ветка else и сообщит об ошибке.
	*/
	char *endptr;
	int num = strtol(argv[1], &endptr, 10);
	if (*endptr == '\0') {
        printf("Number: %d\n", num); 
    } 
	else {
        fprintf(stderr, "Wrong symbols in first argument\n");
    	return 1;
    }
	digital_root(num);

	/*
	Этот код чисто для примера преобразования строки в массив символов
	Преобразование строки в массив int
	Символы цифр в таблице кодировки ASCII идут подряд: '0' = 48, '1' = 49, ..., '9' = 57.
	Вычитая '0' (то есть 48), вы получаете математическое значение цифры: '5' - '0' превращается в 53 - 48 = 5.
	Явное приведение (int) здесь не нужно — язык C автоматически преобразует результат вычитания двух char в тип int при записи в массив.
	*/
	size_t amount_of_digits = strlen(argv[1]);
	int *digits = malloc(amount_of_digits * sizeof(int));
	if (digits == NULL) {
		fprintf(stderr, "Can't allocate memory for digits array\n");
    	return 1; 
	}
	for (size_t i = 0; i < amount_of_digits; i++)
		digits[i]=argv[1][i] - '0';
	free(digits);
	
	return 0;
}