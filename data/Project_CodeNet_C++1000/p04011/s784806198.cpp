#include <cstdio>

int main(){
  int n,k,x,y;
  scanf("%d%d%d%d",&n,&k,&x,&y);
  if(n<=k){
    printf("%d\n",n*x);
  }
  else{
    printf("%d\n",k*x+(n-k)*y);
  }
}