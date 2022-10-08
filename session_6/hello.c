#include<stdio.h>

extern char etext, edata, end; 

int x_init = 10;
int y_uninit;
int main(){
  int z = 0;
  getchar();
  printf("Hello Linux!\n Address of the end of text section is %p, ", &etext);
  
  return 0;
}
