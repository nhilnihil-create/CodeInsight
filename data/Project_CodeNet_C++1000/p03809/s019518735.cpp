#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

typedef long long ll;

inline ll read()
{
	ll x=0;char ch=getchar();
	while(ch<'0' || '9'<ch)ch=getchar();
	while('0'<=ch && ch<='9')x=x*10+(ch^48),ch=getchar();
	return x;
}
inline void chkmax(ll &a,ll b){if(a<b)a=b;}
inline void Return(){puts("NO");exit(0);}

const int N=1e5+9;

ll n,a[N],rt;
vector<int> e[N];

inline void dfs(int u,int fa)
{
	if(u!=rt && e[u].size()==1)
		return;

	ll mx=0,sum=0;
	for(int i=0,v;i<e[u].size();i++)
		if((v=e[u][i])!=fa)
		{
			dfs(v,u);
			sum+=a[v];
			chkmax(mx,a[v]);
		}

	if(sum<a[u] || sum>a[u]*2 || (mx*2>sum?sum-mx:sum/2)<sum-a[u])
		Return();
	a[u]=a[u]*2-sum;
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1,u,v;i<n;i++)
	{
		u=read();v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	rt=1;
	while(e[rt].size()!=1)rt++;

	ll val=a[rt];
	dfs(rt,0);
	if(a[rt]!=val)
		Return();

	puts("YES");
	return 0;
}
