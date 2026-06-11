#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
LL n,a[100010],m,ans[100010],sta[100010],top=0,X[100010],A[100010],k;
bool vis[100010];
void solve(LL x)
{
	top=0;
	while(!vis[x])
	{
		sta[top++]=x;vis[x]=true;
		x=a[x];
	}
	//printf("solve:%lld\n",x);
	//for(int i=0;i<top;i++) printf("%lld ",sta[i]);printf("\n");
	for(LL i=0;i<top;i++) ans[sta[i]]=X[sta[(k+i)%top]];
}
int main()
{
	memset(vis,false,sizeof(vis));
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++) scanf("%lld",&A[i]);
	for(LL i=1;i<=n;i++) a[i]=i,X[i]=A[i]-A[i-1];
	//for(int i=1;i<=n;i++) printf("%lld ",X[i]);printf("\n");
	scanf("%lld %lld",&m,&k);
	for(LL i=1;i<=m;i++)
	{
		LL c;scanf("%lld",&c);
		swap(a[c],a[c+1]);
	}
	//for(int i=1;i<=n;i++) printf("%lld ",a[i]);printf("\n");
	for(LL i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		solve(i);
	}
	//for(int i=1;i<=n;i++) printf("%lld ",ans[i]);printf("\n");
	LL sum=0;
	for(LL i=1;i<=n;i++) sum+=ans[i],printf("%lld.0\n",sum);
}