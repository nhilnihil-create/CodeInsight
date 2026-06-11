#include <stdio.h>

int main() {
  int x,a,b;
  int jarak1,jarak2;
  scanf("%d %d %d",&x,&a,&b);
  jarak1 = x-a;
  jarak2 = x-b;
  if (jarak1<0){
  		jarak1 *= -1;
  }
  if (jarak2<0){
  		jarak2 *= -1;
  }
  if (jarak1<jarak2){
  		printf("A");
  }
  else{
  		printf("B");
  }
  return 0;
}