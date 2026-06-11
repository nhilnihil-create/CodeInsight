#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1e5+5;
int n,a[N],b[N],c[N],tot,sta[N<<1],lcm; ll k;
bool vis[N];
int rdn()
{
  int ret=0;bool fx=1;char ch=getchar();
  while(ch>'9'||ch<'0'){if(ch=='-')fx=0;ch=getchar();}
  while(ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
  return fx?ret:-ret;
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void dfs(int cr)
{
  sta[++tot]=cr;vis[cr]=1;
  if(!vis[b[cr]])dfs(b[cr]);
}
int main()
{
  n=rdn();
  for(int i=1;i<=n;i++)a[i]=rdn();
  for(int i=n;i;i--)a[i]-=a[i-1];
  for(int i=1;i<=n;i++)b[i]=i;
  int m;m=rdn(); scanf("%lld",&k);
  for(int i=1,d;i<=m;i++)
    {
      d=rdn(); swap(b[d],b[d+1]);
    }
  lcm=1;
  for(int i=1;i<=n;i++)
    if(!vis[i])
      {
	tot=0; dfs(i);
	for(int j=tot+1;j<=tot<<1;j++)
	  sta[j]=sta[j-tot];
	int d=k%tot;
	for(int j=1;j<=tot;j++)
	  c[sta[j]]=a[sta[j+d]];
      }
  ll lj=c[1];
  for(int i=1;i<=n;i++,lj+=c[i])
    printf("%lld\n",lj);
  return 0;
}