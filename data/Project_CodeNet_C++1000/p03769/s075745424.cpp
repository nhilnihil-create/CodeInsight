#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<queue>
#define LL long long
using namespace std;
inline LL read( )
{
  LL sum=0;char c=getchar( );bool f=0;
  while(c<'0'||c>'9') {if(c=='-') f=1;c=getchar( );}
  while(c>='0'&&c<='9') {sum=sum*10+c-'0';c=getchar( );}
  if(f) return -sum;
  return sum;
}
LL n;int len;bool p[202];
int main( )
{
  n=read( )+1;
  while(n!=1)
    {
      if(n&1) n--,p[++len]=1;
      else n>>=1,p[++len]=0;
    }
  printf("%d\n",len<<1);
  int i;deque<int>q;
  for(i=len;i>=1;i--)
    p[i]?q.push_front(len-i+1):q.push_back(len-i+1);
  while(!q.empty( )) 
    printf("%d ",q.front( )),q.pop_front( );
  for(i=1;i<=len;i++) printf("%d ",i);
  return 0;
}
     