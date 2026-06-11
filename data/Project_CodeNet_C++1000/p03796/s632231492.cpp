#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void){
  char buf[32] = { 0 };
  int N;
  long power = 1;
  
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d", &N);
  int i = 1;
  while(i <= N){
    power *= i;
    power = power % (1000000007);
    i++;
  }
  printf("%ld\n", power);
  return 0;
}
