#include <stdio.h>

int main(void) {
    printf("Hello World ");
    puts("Hello C");

    const char *hello_world = "Hello World";
    const char *hello_c = "Hello C";

    printf("%s\n", hello_world);
    puts(hello_c);

    return 0;
}