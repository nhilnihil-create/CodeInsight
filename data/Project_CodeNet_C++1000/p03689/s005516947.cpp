#include<stdio.h>
int main(){
  int H, W, h, w;
  scanf("%d%d%d%d", &H,&W,&h,&w);
  if(H%h||W%w){
    puts("Yes");
    for(int i=0; i<H; ++i,puts(""))
      for(int j=0; j<W; ++j)
        if((i+1)%h || (j+1)%w) printf("1000 ");
        else  printf("%d ", -1000*(h*w-1)-1);
  }else puts("No");
  return 0;
}