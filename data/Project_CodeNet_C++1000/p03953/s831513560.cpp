#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;

const int maxn=1e5+15;
ll n,m,k,cnt;
ll vis[maxn],s[maxn],x[maxn],num[maxn],be[maxn],p[maxn],a[maxn];
vector <ll> q[maxn];
void dfs(ll x,ll dep)//找环 
{
	num[x]=dep;vis[x]=1;be[x]=cnt;
	q[cnt].push_back(x);
	if (!vis[p[x]]) dfs(p[x],dep+1);
}
int main()
{
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",x+i);
	for (int i=1;i<n;i++) s[i]=x[i+1]-x[i];//差分序列 
	scanf("%lld%lld",&m,&k);
	for (int i=1;i<n;i++) p[i]=i;
	for (int i=1;i<=m;i++) {scanf("%lld",a+i);swap(p[a[i]],p[a[i]-1]);}//一次置换的结果，记录下一次置换兔子到哪了 
	for (int i=1;i<n;i++) if (!vis[i]) {dfs(i,0);++cnt;}
	ll now=x[1];
	printf("%lld\n",now);
	for (int i=1;i<n;i++)
	{
		now+=s[q[be[i]][(num[i]+k)%q[be[i]].size()]];
		printf("%lld\n",now);
	}
	return 0;
}