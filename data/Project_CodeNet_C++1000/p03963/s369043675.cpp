#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void){
  char buf[32] = { 0 };
  int N,K;
  long ans;
  
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d %d", &N, &K);
  
  ans = K * (long)pow(K-1, (N-1));
  
  printf("%ld\n", ans);
  return 0;
}
