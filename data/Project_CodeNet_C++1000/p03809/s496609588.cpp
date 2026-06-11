#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct node { int t,next; }a[200010];

int head[100010],fa[100010],in[100010],num[100010],n,m,rt,tot;
bool flag;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void add(int x,int y) { a[++tot].t=y;a[tot].next=head[x];head[x]=tot; }

inline void dfs(int x,int y)
{
	if (in[x]==1) { fa[x]=num[x];return; }
	fa[x]=num[x]<<1;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		dfs(t,x);fa[x]-=fa[t];
	}
}

inline void work(int x,int y)
{
	if (in[x]==1) return;
	int hh=0;
	if (fa[x]>num[x]) { flag=false;return; }
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		if (fa[t]>num[x]-fa[x]) hh+=fa[t]+fa[x]-num[x];
		if (hh>fa[x]) { flag=false;return; }
	}
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		work(t,x);
		if (!flag) return;
	}
}

int main()
{
	n=rd();tot=0;
	for (int i=1;i<=n;i++) num[i]=rd();
	if (n==2)
	{
		if (num[1]==num[2]) puts("YES");
		else puts("NO");
		return 0;
	}
	for (int i=1;i<n;i++)
	{
		int x=rd(),y=rd();
		add(x,y);add(y,x);
		in[x]++;in[y]++;
	}
	for (int i=1;i<=n;i++) if (in[i]>1) { rt=i;break; }
	dfs(rt,0);
	if (fa[rt]) { puts("NO");return 0; }
	flag=true;work(rt,0);
	if (flag) puts("YES");
	else puts("NO");
	return 0;
}