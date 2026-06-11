#include<bits/stdc++.h>
using namespace std;

struct node { int t,next; }a[200010];

int head[100010],f[100010],n,tot;

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
	f[x]=0;
	for (int i=head[x];i;i=a[i].next)
	{
		int t=a[i].t;
		if (t==y) continue;
		dfs(t,x);f[x]^=f[t]+1;
	}
}

int main()
{
	n=rd();tot=0;
	for (int i=1;i<n;i++) { int x=rd(),y=rd();add(x,y);add(y,x); }
	dfs(1,0);
	puts(f[1]?"Alice":"Bob");
	return 0;
}