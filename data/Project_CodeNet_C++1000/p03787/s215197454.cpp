#include<bits/stdc++.h>
using namespace std;
long long read()
{
	char ch=getchar();long long x=0,ff=1;
	while(ch<'0'||ch>'9') {if(ch=='-') ff=-ff;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*ff;
}
void write(long long aa)
{
	if(aa<0) putchar('-'),aa=-aa;
	if(aa>9) write(aa/10);
	putchar(aa%10+'0');
	return;
}
long long n,m,ans,X,Y,K,ff,col;
long long vis[200005];
long long tot,head[200005],nx[800005],to[800005];
void jia(long long aa,long long bb)
{
	tot++;
	nx[tot]=head[aa];
	to[tot]=bb;
	head[aa]=tot;
	return;
}
void dfs(int rt)
{
	vis[rt]=col;
	if(rt<=n&&vis[rt+n]==col) ff=1;
	else if(rt>n&&vis[rt-n]==col) ff=1;
	for(int i=head[rt];i;i=nx[i])
	{
		int yy=to[i];
		if(vis[yy]) continue;
		dfs(yy);
	}
	return;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=read();
		jia(x,y+n);jia(y+n,x);
		jia(y,x+n);jia(x+n,y);
	}
	for(int i=1;i<=n*2;++i) if(!vis[i])
	{
		ff=0;++col;dfs(i);
		if(!head[i]) K++;
		else if(!ff) X++;
		else Y++;
	}
	X/=2;K/=2;
	write(X*(2*X+Y)+Y*(X+Y)+K*2*n-K*K);
	return 0;
}