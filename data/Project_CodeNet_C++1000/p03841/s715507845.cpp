#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<utility>
#define gc getchar()
#define fir first
#define sec second
#define N 510
using namespace std;
inline int inn()
{
	int x,ch;while((ch=gc)<'0'||ch>'9');
	x=ch^'0';while((ch=gc)>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^'0');return x;
}
int fa[N*N],ans[N*N];pair<int,int> x[N];
inline int findf(int x)
{
	int fx=x,y;while(fa[fx]^fx) fx=fa[fx];
	while(x^fx) y=fa[x],fa[x]=fx,x=y;return fx;
}
int main()
{
	int n=inn(),tot=n*n;
	for(int i=1;i<=n;i++) x[i].fir=inn(),x[i].sec=i;
	sort(x+1,x+n+1);for(int i=1;i<=tot;i++) fa[i]=i;
	for(int i=n;i>=1;i--)
	{
		int ps=x[i].fir,t=x[i].sec;ans[ps]=t,fa[ps]=ps-1;
		for(int j=1;j<=n-t;j++)
		{
			int p=findf(tot);
			if(p<ps) return !printf("No\n");
			ans[p]=t,fa[p]=p-1;
		}
	}
	for(int i=n,p;i>=1;i--)
		for(int ps=x[i].fir,t=x[i].sec,j=1;j<t;j++)
			if((p=findf(tot))>ps) return !printf("No\n");
			else ans[p]=t,fa[p]=p-1;
	printf("Yes\n");
	for(int i=1;i<=n*n;i++) printf("%d ",ans[i]);
	return !printf("\n");
}