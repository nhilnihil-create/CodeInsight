#include <stdio.h>
int main(){
  int n; scanf("%d", &n);
  int x = 0;
  int l, r;
  for (int i=0;i<n;i++){
    scanf("%d %d", &l, &r);
    x += r-l+1;
  }
  printf("%d", x);
  return 0;
}