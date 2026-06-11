#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 100127
int n,m,c[N],ans[N];
struct C{int l,r;}q[N*3];
inline bool cmp(C x,C y){return (x.r-x.l)<(y.r-y.l);}
inline void change(int x,int v)
{for(;x<=n;x+=x&(-x))c[x]+=v;}
inline int Ask(int x)
{int res=0;for(;x;x-=x&(-x))res+=c[x];return res;}
int main(){
	scanf("%d%d",&m,&n);int i,j,p;
	for(i=1;i<=m;i++)scanf("%d%d",&q[i].l,&q[i].r);
	sort(q+1,q+m+1,cmp);p=1;
	for(i=1;i<=n;i++)
	{
		while((p<=m)&&(q[p].r-q[p].l+1<i))
		{change(q[p].l,1);change(q[p].r+1,-1);++p;}
		ans[i]=m-p+1;
		for(j=0;j<=n;j+=i)ans[i]+=Ask(j);
	}
	for(i=1;i<=n;i++)
	printf("%d\n",ans[i]);return 0;
}