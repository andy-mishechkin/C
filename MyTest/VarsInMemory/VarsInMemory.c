#include <stdio.h>

unsigned char e=0xab;
unsigned char *b = &e;

char ch1 = 'a', ch2 = 'b', ch3 = 'c', ch4 = 'd', ch5 = 'e';

short int si1 = 1, si2 = 2, si3 = 3, si10 = 10, si16 = 15, si23 = 23;
int i1 = 1, i2 = 2, i3 = 3, i10 = 10, i16 = 15, i23 = 23;

double number = 3.14159;

unsigned short int c=0x1234;
unsigned int t=0x34567890;
long long unsigned int a=0x6178569812324572;

void main()
{
    
    printf("sizeof(int): %lu\n", sizeof(int));
    printf("sizeof(short int): %lu\n", sizeof(short int));
    printf("sizeof(char): %lu\n", sizeof(char));
    printf("sizeof(long): %lu\n", sizeof(long));
    printf("sizeof(unsigned long long): %lu\n", sizeof(unsigned long long));

    int j=0;
    printf("\n%p   ",b);
    for(int i=0; i<400; i++)
    {
        printf("%02x  ",*(b++));
        if (++j==16 && i<398) 
        {
            printf("\n");
            j=0;
            printf("%p   ",b);
        };
    };
    printf("\n");
};