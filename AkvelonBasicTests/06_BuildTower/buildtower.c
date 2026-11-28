/*
Build a pyramid-shaped tower, as an array/list of strings, given a positive integer number of floors. 
A tower block is represented with "*" character.
For example, a tower with 3 floors looks like this:
[
  "  *  ",
  " *** ", 
  "*****"
]
And a tower with 6 floors looks like this:
[
  "     *     ", 
  "    ***    ", 
  "   *****   ", 
  "  *******  ", 
  " ********* ", 
  "***********"
]
*/

#include <stdio.h>
#include <stdlib.h>

int str_to_num(char *str){
  char *endptr;
	int num = strtol(str, &endptr, 10);
	if (*endptr == '\0')
    return num; 
	else
    return -1;
} 

void build_tower(int n) { 
  int floor_row = n*2 - 1;
  int floor_center = n - 1;

  char tower[n][floor_row];
	for(int i = 0; i < n; i++) {
    int filled = 0;
    for(j = floor_center; j > 0; j--) {
      if (filled  )
    }
      
  }
}

int main(int argc, char *argv[]) {
	if(argc < 2) {
		fprintf(stderr, "Please enter amount of floors\n");
		return 1;
	}

  int num_of_floors = str_to_num(argv[1]);
  if (num_of_floors == -1) {
    fprintf(stderr, "Wrong amount of symbols has been specified\n");
		return 1;
  }
  build_tower(num_of_floors);
  return 0;
}