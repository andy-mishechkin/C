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

void print_array(const char arr[], int len) {
    for (size_t i = 0; i < len; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}


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
    int c_up = floor_center;
    for(int c_down = floor_center; c_down > 0; c_down--) {
      if (c_down >= (floor_center - i))
        tower[i][c_down] = '*';
      else
        tower[i][c_down] = ' ';
      
      if (c_up <= (floor_center + i))
        tower[i][c_up] = '*';
      else
        tower[i][c_up] = ' ';
      c_up++;
    }
    print_array(tower[i], floor_row);
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