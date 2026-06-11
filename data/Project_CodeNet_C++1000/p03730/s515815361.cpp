#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void){
  char buf[64] = { 0 };
  int A,B,C;
  
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d %d %d", &A, &B, &C);
  
  int flag = 0;
  for(int i = 0; i < A; i++){
    int ans = (i * B + C) % A;
    if(ans == 0){
      flag = 1;
      break;
    }
  }
  
  if(flag) printf("YES\n");
  else printf("NO\n");
  return 0;
}
