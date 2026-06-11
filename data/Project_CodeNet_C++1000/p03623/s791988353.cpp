#include <stdio.h>

int main() {
 int x, a, b;
 int A, B;
 scanf("%d %d %d", &x, &a, &b);
 if(x-a < 0){
  A = (x-a) * -1;
 }
  else if(x-a>=0){
   A= x-a;
  }
 if(x-b < 0){
  B = (x-b) * -1;
 }
  else if(x-b>=0){
   B= x-b;
  }
 if(A>B){
  printf("B");
 }
 else if(B>A){
  printf("A");
 }
 return 0;
}