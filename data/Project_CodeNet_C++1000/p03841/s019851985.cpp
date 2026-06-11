#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define P pair<int,int>
const LL inf = 0x3f3f3f3f;
const LL mod = 924844033;
const LL N = 1e5+10;
template <typename tp> inline void read(tp &x)
{
	x=0;char c=getchar();int f=0;
	for(;c>'9'||c<'0';f|=(c=='-'),c=getchar());
	for(;c<='9'&&c>='0';x=(x<<3)+(x<<1)+c-'0',c=getchar());
	if(f) x=-x;
}
int n,now;
P x[510];
int ans[250010];
signed main()
{
	read(n);now=n*n;
	for(int i=1;i<=n;i++) x[i].second=i,read(x[i].first),ans[x[i].first]=i;
	sort(x+1,x+n+1);
	for(int i=n;i>=1;i--)
	{
		int zz=x[i].second;
		int flag=n-zz;
		while(flag)
		{
			if(ans[now]==zz) return 0*puts("No");
			if(!ans[now]) ans[now]=zz,flag--;
			now--;if(now<=0) return 0*puts("No");
		}
	}
	now=1;
	for(int i=1;i<=n;i++)
	{
		int zz=x[i].second;
		int flag=zz-1;
		while(flag)
		{
			if(ans[now]==zz) return 0*puts("No");
			if(!ans[now]) ans[now]=zz,flag--;
			now++;if(now>n*n) return 0*puts("No");
		}
	}
	puts("Yes");
	for(int i=1;i<=n*n;i++) printf("%d ",ans[i]);
	puts("");
	return 0;
}