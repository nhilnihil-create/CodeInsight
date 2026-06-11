#include<cstdio>

int main(){
  long long x, y;
  scanf("%lld%lld", &x, &y);
  if(x-y <= 1 && y-x <= 1) printf("Brown\n");
  else printf("Alice\n");
}