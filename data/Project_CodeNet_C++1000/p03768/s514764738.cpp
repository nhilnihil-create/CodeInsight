#include<bits/stdc++.h>
using namespace std;
inline int read(int &a){a=0;int f=1;char c=getchar();
for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
for(;c<='9' && c>='0';a=a*10+c-'0',c=getchar());return a*=f;}
inline void print(int a){int s[20],t=0;if(!a){putchar('0');putchar('\n');return;}
while(a){s[t++]=a%10,a/=10;}for(;t--;putchar(s[t]+'0'));putchar('\n');}
struct pricture{
	int next,y;
} e[200010];
int link[100010],lin;
void add(int a,int b){e[++lin].next=link[a],link[a]=lin,e[lin].y=b;}
int n,m,q;
int v[100010],d[100010],c[100010];
int s[100010],a[100010];

void dfs(int x,int d,int l)
{
	if(!a[x]) a[x]=l;
	if(!d || s[x]>=d) return;
	s[x]=d;
	for(int i=link[x];i;i=e[i].next)
	dfs(e[i].y,d-1,l);
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=m;i++)
	{
		int s,t;
		read(s),read(t);
		add(s,t);
		add(t,s);
	}
	read(q);
	for(int i=1;i<=q;i++) read(v[i]),read(d[i]),read(c[i]);
	for(int i=q;i>=1;i--) dfs(v[i],d[i],c[i]);
	for(int i=1;i<=n;i++) print(a[i]);
	return 0;
}