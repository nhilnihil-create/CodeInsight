#include<stdio.h>
int main(void){
  int n,res,l,r;
  scanf("%d",&n);
  for(int loop=0;loop<n;loop++){
    scanf("%d %d",&l,&r);
    res+=r-l+1;
  }
  printf("%d\n",res);
}