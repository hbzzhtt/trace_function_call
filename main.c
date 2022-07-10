#include <stdio.h>

int foo(void) {  
  return 2; 
}

int bar(void) {
  zoo();
  return 1;
}

void zoo(void) { 
  foo(); 
}

int main(int argc, char **argv) { 
  bar(); 
}
