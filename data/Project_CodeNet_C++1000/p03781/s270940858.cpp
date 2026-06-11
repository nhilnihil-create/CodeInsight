#include<stdio.h>
int main(){
  int x;
  scanf("%d",&x);
  int i,a=0;
  for(i=1;i<=x;i++){
    a=a+i;
    if(a>=x){
      printf("%d",i);
      break;
    }
  }

  return 0;
}

