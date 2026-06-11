#include <cstdio>
long long n,m;
int main(){
  scanf("%lld %lld",&n,&m);
  long long x=0;
  if(m<=n*2)x=m/2;
  else x=(n*2+m)/4;
  printf("%lld",x);
}
