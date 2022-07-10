#include <stdio.h>

int foo(double) {  
  return 2; 
}

void zoo(int ); 

int bar(void) {
  zoo(2);
  return 1;
}

void zoo(int) { 
  foo(1.1f); 
}

int main(int argc, char **argv) { 
  bar(); 
}
