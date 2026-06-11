#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<queue>
#define LL long long
using namespace std;
inline int read( )
{
  int sum=0;char c=getchar( );bool f=0;
  while(c<'0'||c>'9') {if(c=='-') f=1;c=getchar( );}
  while(c>='0'&&c<='9') {sum=sum*10+c-'0';c=getchar( );}
  if(f) return -sum;
  return sum;
}
const int mod=1000000007;
const int N=1000005;
int n,n2,f[N],sm[N];
inline void up(int &x,int y) {x+=y;if(x>=mod) x-=mod;}
int main( )
{
  int i,j;
  n=read( );j=n-2;n2=(LL)(n-1)*(n-1)%mod;
  f[0]=1;sm[0]=1;
  for(i=1;i<=n;i++)
    {
      f[i]=(i>=3)?sm[i-3]:0;sm[i]=sm[i-1];
      up(f[i],f[i-1]);up(sm[i],f[i]);
    }
  int ans=0;
  for(i=0;i<=j;i++) up(ans,(LL)f[i]*n2%mod); //_+XY
  for(i=0;i<=j;i++) up(ans,(LL)f[i]*(i+1)%mod); //_+X+X*1 over n
  up(ans,(LL)f[n-1]*(n-1)%mod); //_+X
  printf("%d",(ans+f[n])%mod); //_
  return 0;
}