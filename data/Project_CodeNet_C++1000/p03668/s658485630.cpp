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
int n;
int f[200005],g[200005];
int tot,head[200005],nx[400005],to[400005];
void jia(int aa,int bb)
{
	tot++;
	nx[tot]=head[aa];
	to[tot]=bb;
	head[aa]=tot;
	return;
}
void dfs(int rt,int fa)
{
	int sum=0,cs=0;g[rt]=0;
	for(int i=head[rt];i;i=nx[i])
	{
		int yy=to[i];
		if(yy==fa) continue;
		dfs(yy,rt);sum+=f[yy];cs++;
		g[rt]^=(g[yy]+1);
	}
	if(sum%2||cs%2) f[rt]=1;
	return;
}
int main()
{
	n=read();
	for(int i=1;i<n;++i)
	{
		int x=read(),y=read();
		jia(x,y);jia(y,x);
	}
	dfs(1,1);
	if(g[1]) puts("Alice");
	else puts("Bob");
	return 0;
}