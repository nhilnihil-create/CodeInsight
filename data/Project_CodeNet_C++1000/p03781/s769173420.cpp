#include<cstdio>
main() {
  int x, i;
  scanf("%d",&x);
  for(i=1;;i++){
    x-=i;
    if(x<=0){printf("%d",i);return 0;}
  }
}