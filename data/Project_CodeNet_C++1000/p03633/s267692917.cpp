#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
  if(b==0)return a;
  return gcd(b,a%b);
}

long long gcm(long long a,long long b)
{
  long long g=gcd(a,b);
  return (a/g)*(b/g)*g;
}

int main()
{
  int N;scanf("%d",&N);
  long long T[N];
  for(int i=0;i<N;i++)scanf("%lld",&T[i]);
  long long g=T[0];
  for(int i=1;i<N;i++)g=gcm(g,T[i]);
  printf("%lld",g);
}