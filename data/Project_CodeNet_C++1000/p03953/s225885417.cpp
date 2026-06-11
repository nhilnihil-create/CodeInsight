#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
#define ll long long
using namespace std;
ll f[N],p[N],s[N],ans[N];
int n;
void get_nxt(ll f[],const ll g[])
{
	for(int i=1;i<=n;i++) s[i]=f[g[i]];
	for(int i=1;i<=n;i++) f[i]=s[i];
}
void ksm(ll f[],ll k)
{
	for(int i=1;i<=n;i++) ans[i]=i;
	for(;k;k>>=1)
	{
		if(k&1) get_nxt(ans,f);
		get_nxt(f,f);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&f[i]),p[i]=i;
	int m;
	ll k;
	scanf("%d%lld",&m,&k);
	for(int i=1;i<=m;i++)
	{
		int a;
		scanf("%d",&a);
		swap(p[a],p[a+1]);
	}
	ksm(p,k);
	for(int i=1;i<=n;i++) printf("%lld\n",s[i]=s[i-1]+f[ans[i]]-f[ans[i]-1]);
	return 0;
}