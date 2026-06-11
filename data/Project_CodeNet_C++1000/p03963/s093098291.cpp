#include<stdio.h>

int main(int argc, char *argv[]){
  int n, k;
  scanf("%d %d", &n, &k);

  long out = k;
  for(int i=2; i<=n; i++){
    out = out * (k - 1);
  }

  printf("%d\n", out);
}
