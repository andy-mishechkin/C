/*
Write a method that takes an array of consecutive (increasing) letters as input and that returns the missing letter in the array.
You will always get an valid array. And it will be always exactly one letter be missing. The length of the array will always be at least 2.
The array will always contain letters in only one case.

['a','b','c','d','f'] -> 'e'
['O','Q','R','S'] -> 'P'
*/
#include <stdio.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
		fprintf(stderr, "Please enter the source string\n");
		return 1;
	}

    return 0;
}