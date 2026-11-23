/*
Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.
move_zeros(10, int [] {1, 2, 0, 1, 0, 1, 0, 3, 0, 1}); // -> int [] {1, 2, 1, 1, 3, 1, 0, 0, 0, 0}
*/
#include <stdio.h>

/*
В C массивы при передаче в функцию неявно преобразуются (распадаются) в указатель на первый элемент. 
Внутри функции sizeof(arr) вернет размер самого указателя (обычно 4 или 8 байт), а не всего массива.
Павильно делать: передавать длину отдельным аргументом
*/

void print_array(const char *label, const int arr[], size_t len) {
    printf("%s", label);
    for (size_t i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//My function with bug (this is a just training) - cant move is zeros are consecutive [1,0,0,2,3]
void move_zeros(int arr[], size_t len) {
    print_array("Source array:", arr, len);
    // Излишнаяя сложность - два раза проход по массиву
    for (size_t i = 0; i < len; i++) {
        if (arr[i] == 0) {
            for(size_t j = i; j < len - 1; j++) {
                arr[j] = arr[j + 1];
            }
            arr[len - 1] = 0;
        }
    }
    print_array("Target array:", arr, len);
}

//Исправленная функция
void move_zeros2(int arr[], size_t len) {
    print_array("Source array:", arr, len);
    size_t pos = 0;
    for (size_t i = 0; i < len; i++) {
        if (arr[i] != 0) {
            /*
            pos++ (постфиксный инкремент) cначала подставляет текущее значение pos как индекс для записи (arr[pos] = arr[i]).
            cразу после этого увеличивает pos на единицу (pos = pos + 1)
            Инкремент происходит «потом» из-за использования постфиксной формы оператора (pos++), 
            которая сначала возвращает текущее значение переменной для операции и только затем увеличивает её на единицу.
            • ++pos (префиксный): Сначала прибавляем 1, потом используем новое значение. 
            Если написать arr[++pos] = arr[i], первый элемент массива (arr[0]) останется пустым или нетронутым, 
            так как запись начнется сразу с индекса 1.
            */
            arr[pos++] = arr[i];
        }
    }
    while (pos < len) {
        arr[pos++] = 0;
    }
    print_array("Target array:", arr, len);
}

int main() {

    int arr1[] = {1, 0, 0, 1, 0, 1, 0, 3, 0, 1};
    int arr2[] = {0, 0, 4, 2, 0, 1, 0, 1, 0, 3, 0, 1, 5, 8, 6, 8, 9, 0, 9};

    size_t arr1_length = sizeof(arr1)/sizeof(arr1[0]);
    size_t arr2_length = sizeof(arr2)/sizeof(arr2[0]);

    move_zeros(arr1, arr1_length);
    move_zeros(arr2, arr2_length);

    move_zeros2(arr1, arr1_length);
    move_zeros2(arr2, arr2_length);
    
    return 0;
}