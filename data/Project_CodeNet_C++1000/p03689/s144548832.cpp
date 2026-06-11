#include<stdio.h>
int main(){
  int H, W, h, w;
  scanf("%d%d%d%d", &H,&W,&h,&w);
  if(H%h==0 && W%w==0){
    puts("No");
    return 0;
  }
  puts("Yes");
  for(int i=0; i<H; ++i,puts(""))
    for(int j=0; j<W; ++j)
      if(i%h==h-1 && j%w==w-1) printf("-999999 ");
      else if(i%h==0 && j%w==0) printf("999998 ");
      else printf("0 ");
  return 0;
}