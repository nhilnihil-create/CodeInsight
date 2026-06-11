#include <bits/stdc++.h>
using namespace std;
const int maxn=110000;
long long a[maxn];
const int INF=1<<30;
int n;
long long l;
long long q;
int f[maxn][35]={};
inline void init()
{
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    scanf("%d",a+i);
  scanf("%d%d",&l,&q);
  for(int i=1;i<=n;i++)
  {
    int x=(int)(upper_bound(a+1,a+n+1,a[i]+l)-a-1);
    f[i][0]=x;
  }
  for(int j=1;j<=30;j++)
  {
    for(int i=1;i<=n;i++)
      f[i][j]=f[f[i][j-1]][j-1];
  }
}
inline void work_()
{
  while(q--)
  {
    long long a,b;
    scanf("%lld %lld",&a,&b);
    if(a>b)
      swap(a,b);
    int ans=0;
    int cur=a;
    for(int i=30;i>=0;i--)
    {
	  if(f[cur][i]<b)
	  {
	    ans+=1<<i;
	    cur=f[cur][i];
	  }
	}
	printf("%d\n",ans+1);
  }
}
int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	init();
	work_();
	return 0;
}