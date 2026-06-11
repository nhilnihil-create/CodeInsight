#include<bits/stdc++.h>
using namespace std;

int gcd(int x,int y)
{
  int ret=1;
  for(int i=2;i<=min(x,y);i++)if(x%i==0&&y%i==0)ret=i;
  return ret;
}

int main()
{
  int A,B,C;
  scanf("%d %d %d",&A,&B,&C);
  int g=gcd(A,B);
  if(C%g==0)printf("YES\n");
  else printf("NO\n");
  return 0;
}