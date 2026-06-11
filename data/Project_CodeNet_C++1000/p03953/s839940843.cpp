#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef double db;
int const xn=1e5+5;
int n,m,a[xn],t[xn],p[xn];
db d[xn],tt[xn];
ll k;
ll rd()
{
  ll ret=0,f=1; char ch=getchar();
  while(ch<'0'||ch>'9'){if(ch=='-')f=0; ch=getchar();}
  while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
  return f?ret:-ret;
}
void pw()
{
  memcpy(t,p,sizeof t);
  for(int i=1;i<=n;i++)p[i]=t[t[i]];//n
}
void ch()
{
  memcpy(tt,d,sizeof tt);
  for(int i=1;i<=n;i++)d[i]=tt[p[i]];
}
int main()
{
  n=rd(); db x=0,pr=0;
  for(int i=1;i<=n;i++)scanf("%lf",&x),d[i]=x-pr,pr=x;
  m=rd(); k=rd();
  for(int i=1;i<=m;i++)a[i]=rd();
  for(int i=1;i<=n;i++)p[i]=i;
  for(int i=1;i<=m;i++)swap(p[a[i]],p[a[i]+1]);
  for(;k;k>>=1ll,pw())
    {
      if(k&1)ch();
    }
  db pos=0;
  for(int i=1;i<=n;i++)
    pos+=d[i],printf("%.1f\n",pos);
  return 0;
}