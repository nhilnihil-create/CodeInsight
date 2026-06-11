#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef unsigned long long int ULONG;

int main(void){
  char buf[64] = { 0 };
  ULONG a,b,x;
  
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%ld %ld %ld", &a, &b, &x);
  
  ULONG ans = b/x - a/x;
  if(a % x == 0) ans++;
  
  printf("%ld\n", ans);
  return 0;
}
