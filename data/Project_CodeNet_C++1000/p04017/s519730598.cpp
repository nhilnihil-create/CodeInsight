#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn=110000;
ll a[maxn];
int n;
ll l;
ll q;
int f[maxn][35]={};
inline void init()
{
  scanf("%d",&n); for(int i=1;i<=n;i++) scanf("%d",a+i); scanf("%d%d",&l,&q);
  for(int i=1;i<=n;i++)
  {
    int x=(int)(upper_bound(a+1,a+n+1,a[i]+l)-a-1);
    f[i][0]=x;
  }
  for(int j=1;j<=30;j++) for(int i=1;i<=n;i++)  f[i][j]=f[f[i][j-1]][j-1];
}
int main()
{
	init();
	while(q--)
    {
      ll a,b;
      scanf("%lld %lld",&a,&b);
      if(a>b)
        swap(a,b);
      int ans=0;
      int cur=a;
      for(int i=30;i>=0;i--)
	    if(f[cur][i]<b)
	    {
	      ans+=1<<i;
	      cur=f[cur][i];
	    }
      printf("%d\n",ans+1);
    }
	return 0;
}
