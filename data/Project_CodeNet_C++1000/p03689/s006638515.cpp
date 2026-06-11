#include<stdio.h>
#define R(i,y,k) for(int i=1;i<=y;++i,k)
int main(){
  int H,W,h,w;
  scanf("%d%d%d%d",&H,&W,&h,&w);
  if(H%h||W%w){
    puts("Yes");
    R(i,H,puts(""))
      R(j,W,1)
        if(i%h||j%w) printf("1000 ");
        else printf("%d ", -1000*(h*w-1)-1);
  }else puts("No");
  return 0;
}