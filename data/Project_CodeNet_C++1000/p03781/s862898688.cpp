#include<cstdio>
int main(void) {
  int n;
  scanf("%d",&n);
  int i=1,j=0;
  for(; j<n; j+=i++);
  printf("%d\n",i-1);
}