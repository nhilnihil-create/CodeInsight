#include<cstdio>
int main(){
  int x,y;
  scanf("%d %d",&x,&y);
  if(-1<=x-y&&x-y<=1){
    printf("Brown\n");
  }else{
    printf("Alice\n");
  }
}