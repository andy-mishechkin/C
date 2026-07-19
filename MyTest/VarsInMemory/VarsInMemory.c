#include <stdio.h>

unsigned char e=0xab;
unsigned char *b = &e;

char ch = 'e';

unsigned short int c=0x1234;
unsigned int t=0x34567890;
long long unsigned int a=0x6178569812324572;

void main()
{
  int j=0;
  printf("\n%p   ",b);
  for(int i=0; i<400; i++)
  {
    printf("%02x  ",*(b++));
    if (++j==16 && i<398) {
       printf("\n");
       j=0;
       printf("%p   ",b);
    };
  };
  printf("\n");
};
