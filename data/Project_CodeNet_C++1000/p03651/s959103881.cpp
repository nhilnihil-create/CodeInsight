#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
  if(b==0)return a;
  return gcd(b,a%b);
}

int main()
{
  int N,K;scanf("%d %d",&N,&K);
  int A[N];for(int i=0;i<N;i++)scanf("%d",&A[i]);
  int g=A[0],mx=A[0];
  for(int i=1;i<N;i++)g=gcd(g,A[i]),mx=max(mx,A[i]);
  if(K<=mx&&K%g==0)printf("POSSIBLE\n");
  else printf("IMPOSSIBLE\n");
}