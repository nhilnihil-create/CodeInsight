#include <stdio.h>
int N; 
int main() {
  scanf("%d",&N);
  if(N%10==9||N/10==9)puts("Yes");
  else puts("No");
}