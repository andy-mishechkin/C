#include <stdio.h>

typedef enum { CHAR, INT, SINT, UINT, USINT, LLUINT, DOUBLE } Type;

unsigned char e=0xab, *b = &e;

char ch1 = 'a', ch2 = 'b', ch3 = 'c', ch4 = 'd', ch5 = 'e';

short int si1 = 1, si2 = 2, si3 = 3, si10 = 10, si15 = 15, si23 = 23;
int i1 = 1, i2 = 2, i3 = 3, i10 = 10, i15 = 15, i23 = 23;

double pi = 3.14159;

unsigned short int c=0x1234;
unsigned int t=0x34567890;
long long unsigned int a=0x6178569812324572;

void var_info(char *vname, void *v, Type vtype)
{   
    size_t typesize;
    char *cpv = (char*)v;

    printf("Variable %s in memory:\n", vname);
    switch(vtype)
    {
        case CHAR:
        {
            char cv = *(char*)v;
            typesize = sizeof(char);
            printf("Variabe value: %c, type: char\n", cv);
            break;
        }
        case INT:
        {
            int iv = *(int*)v;
            typesize = sizeof(int);
            printf("Variabe value: %d, type: int\n", iv);
            break;
        }
        case UINT:
        {
            unsigned int uiv = *(unsigned int*)v;
            typesize = sizeof(unsigned int);
            printf("Variabe value: %u, type: unsigned int\n", uiv);
            break;
        }
        case SINT:
        {
            short int siv = *(short int*)v;
            typesize = sizeof(short int);
            printf("Variabe value: %hd, type: short int\n", siv);
            break;
        }
        case USINT:
        {
            unsigned short int usiv=*(unsigned short int*)v;
            typesize = sizeof(short int);
            printf("Variabe value: %hu, type: unsigned short int\n", usiv);
            break;
        }
        case LLUINT:
        {
            long long unsigned int lluiv=*(long long unsigned int*)v;
            typesize = sizeof(long long unsigned int);
            printf("Variabe value: %llu, type: long long unsigned int\n", lluiv);
            break;
        }
        case DOUBLE:
        {
            double dv = *(double*)v;
            typesize = sizeof(double);
            printf("Variabe value: %lf, type: double\n", dv);
            break;
        }
    }
    printf("bytes in memory: %lu\n", typesize);
    for(int i=0; i<typesize; i++)
    {
        printf("%p: %x\n", cpv, *cpv & 0xFF);
        cpv++;
    }
    printf("\n");
}

void main()
{    
    var_info("e", &e, CHAR);
    var_info("ch1", &ch1, CHAR);
    var_info("ch2", &ch2, CHAR);
    var_info("ch3", &ch3, CHAR);
    var_info("ch4", &ch4, CHAR);
    var_info("ch5", &ch5, CHAR);

    var_info("si1", &si1, SINT);
    var_info("si2", &si2, SINT);
    var_info("si3", &si3, SINT);
    var_info("si10", &si10, SINT);
    var_info("si15", &si15, SINT);
    var_info("si23", &si23, SINT);

    var_info("i1", &i1, INT);
    var_info("i2", &i2, INT);
    var_info("i3", &i3, INT);
    var_info("i10", &i10, INT);
    var_info("i15", &i15, INT);
    var_info("i23", &i23, INT);

    var_info("pi", &pi, DOUBLE);
    var_info("c", &c, USINT);
    var_info("t", &t, UINT);
    var_info("a", &a, LLUINT);

    printf("Raw memory map output.\n");
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