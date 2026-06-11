#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100005;

int n,m,tot,ans[N],c[N];
struct data{int x,y,l,r,id,c;}a[N*3],q[N*50];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

bool cmp(data a,data b)
{
	return a.x<b.x;
}

void ins(int x,int y)
{
	while (x<=m) c[x]+=y,x+=x&(-x);
}

int query(int x)
{
	int ans=0;
	while (x) ans+=c[x],x-=x&(-x);
	return ans;
}

int main()
{
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
	sort(a+1,a+n+1,cmp);
	for (int i=2;i<=m;i++)
	{
		for (int j=i;j<=m;j+=i)
		{
			q[++tot].x=j-i;q[tot].l=j-i+1;q[tot].r=j-1;q[tot].id=i;q[tot].c=1;
			q[++tot].x=j-1;q[tot].l=j-i+1;q[tot].r=j-1;q[tot].id=i;q[tot].c=-1;
		}
		int x=(m/i)*i;
		q[++tot].x=x;q[tot].l=x+1;q[tot].r=m;q[tot].id=i;q[tot].c=1;
		q[++tot].x=m;q[tot].l=x+1;q[tot].r=m;q[tot].id=i;q[tot].c=-1;
	}
	sort(q+1,q+tot+1,cmp);
	for (int i=1;i<=m;i++) ans[i]=n;
	int now=1;
	for (int i=1;i<=tot;i++)
	{
		while (now<=n&&a[now].x<=q[i].x) ins(a[now].y,1),now++;
		ans[q[i].id]+=q[i].c*(query(q[i].r)-query(q[i].l-1));
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}