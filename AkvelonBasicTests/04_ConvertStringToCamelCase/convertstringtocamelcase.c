/*
Complete the method/function so that it converts dash/underscore delimited words into camel casing. 
The first word within the output should be capitalized only if the original word was capitalized 
(known as Upper Camel Case, also often referred to as Pascal case). The next words should be always capitalized.
Examples
"the-stealth-warrior" gets converted to "theStealthWarrior"
"The_Stealth_Warrior" gets converted to "TheStealthWarrior"
"The_Stealth-Warrior" gets converted to "TheStealthWarrior"
do not allocate memory for the result
write to pre-allocated pointer *camel
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Моя функция с замечаниями
void to_camel_case(const char *text, char *camel) {
    while (*text != '\0') {
        if (isalnum((unsigned char)*text))
            *camel = *text;
        else {
            text++;
            *camel=toupper((unsigned char)*text);
        }
        text++;
        camel++;
    }
    *camel='\0';
}

//Исправленная функция
void to_camel_case2(const char *text, char *camel) {
    int capitalize_next = 0;

    while (*text != '\0') {
        if (isalnum((unsigned char)*text)) {
            if (capitalize_next) {
                *camel = toupper((unsigned char)*text);
                capitalize_next = 0;
            } 
            else 
                *camel = *text;
            camel++;
        } 
        else 
            capitalize_next = 1;
        text++;
    }
    *camel = '\0';
}

int main() {
    /*
    Старый неоптимизрованный код с копипастом, оставлен для описания процесса рефакторинга

    char originStr1[] = "the-stealth-warrior";
    char *ccStr1 = malloc(strlen(originStr1));
    printf("Original string: %s\n", originStr1);
    to_camel_case(originStr1, ccStr1);
    printf("Camel case string: %s\n", ccStr1);
    free(ccStr1);


    char originStr2[] = "The_Stealth_Warrior";
    char *ccStr2 = malloc(strlen(originStr2));
    printf("\nOriginal string: %s\n", originStr2);
    to_camel_case(originStr2, ccStr2);
    printf("Camel case string: %s\n", ccStr2);
    free(ccStr2);

    char originStr3[] = "The_Stealth-Warrior";
    char *ccStr3 = malloc(strlen(originStr3));
    printf("\nOriginal string: %s\n", originStr3);
    to_camel_case(originStr3, ccStr3);
    printf("Camel case string: %s\n", ccStr3);
    free(ccStr3);
    */

    const char *tests[] = {
        "the-stealth-warrior",
        "The_Stealth_Warrior",
        "The_Stealth-Warrior"
    };

    for (int i = 0; i < 3; i++) {
        // +1 байт для завершающего '\0' - хотя это не нужно для строк с разделителями, которые удаляются
        // +1 добавляется чисто для безопасности работы функции to_camel_case
        char *ccStr = malloc(strlen(tests[i]) + 1);
        if (ccStr == NULL) return 1;

        printf("Original string: %s\n", tests[i]);
        to_camel_case2(tests[i], ccStr);
        printf("Camel case string: %s\n\n", ccStr);

        free(ccStr); // Освобождаем память
    }

    return 0;
}