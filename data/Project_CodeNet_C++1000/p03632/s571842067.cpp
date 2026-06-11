#include<stdio.h>

int main(int argc, char *argv[]){
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);

  int start = a;
  if(a < c) start = c;

  int end = b;
  if(b > d) end = d;

  int out = end - start;
  if(out < 0) out = 0;

  printf("%d\n", out);

  return 0;
}
