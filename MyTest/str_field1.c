#include <stdio.h>
 
struct person {
    int age;
    char* name;
};
 
int main(void){
 
    struct person tom = {.age = 40, .name ="Tom"};
    // получаем размер структуры person
    printf("sizeof(struct person): %lu\n", sizeof(struct person));
    // получаем адрес переменной tom
    printf("structure tom address: %p\n", &tom);
    // получаем адрес поля age в переменной tom
    printf("field age address: %p\n", &tom.age);
    // получаем адрес поля name в переменной tom
    printf("field name address: %p\n", &tom.name);
    return 0;
}