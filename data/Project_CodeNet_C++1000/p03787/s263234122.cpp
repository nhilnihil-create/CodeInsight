#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

int fa[100010],num[100010],n,m,cnt;
bool bo[100010],pd[100010];
ll ans;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int find(int x)
{
	if (!fa[x]) return x;
	int hh=find(fa[x]);
	num[x]^=num[fa[x]];
	return fa[x]=hh;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd();
		bo[x]=true;bo[y]=true;
		int f1=find(x),f2=find(y);
		if (f1<f2) { swap(f1,f2);swap(x,y); }
		if (f1==f2&&num[x]==num[y]) pd[f1]=1;
		if (f1==f2) continue;
		pd[f2]|=pd[f1];fa[f1]=f2;
		num[f1]=num[x]^num[y]^1;
	}
	for (int i=1;i<=n;i++) if (!bo[i]) cnt++;
	ans=(ll)cnt*(n-cnt)*2+(ll)cnt*cnt;
	cnt=0;
	for (int i=1;i<=n;i++) if (bo[i]&&!fa[i]) cnt++;
	ans+=(ll)cnt*cnt;
	cnt=0;
	for (int i=1;i<=n;i++) if (bo[i]&&!fa[i]&&!pd[i]) cnt++;
	for (int i=1;i<=n;i++) if (bo[i]&&!fa[i]&&!pd[i]) ans+=(ll)cnt;
	printf("%lld\n",ans);
	return 0;
}