#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void){
  char buf[32] = { 0 };
  int A,B,C,D;
  int time = 0;
  
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d %d %d %d", &A, &B, &C, &D);
  
  if(A < C){
    if(B < C) time = 0;
    else{
      if(D < B) time = D - C;
      else time = B - C;
    }
  }
  else{
    if(D < A) time = 0;
    else{
      if(B < D) time = B - A;
      else time = D - A;
    }
  }
  printf("%d\n", time);
  return 0;
}
