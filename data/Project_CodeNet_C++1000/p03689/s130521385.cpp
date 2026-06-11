#include<stdio.h>
int main(){
  int H,W,h,w;
  scanf("%d%d%d%d",&H,&W,&h,&w);
  if(H%h||W%w){
    puts("Yes");
    for(int i=1;i<=H;++i,puts("")) for(int j=1;j<=W;++j)
      if(i%h||j%w) printf("1000 ");
      else printf("%d ", -1000*(h*w-1)-1);
  }else puts("No");
  return 0;
}