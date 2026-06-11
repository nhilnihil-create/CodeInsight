//Love and Freedom.
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#define inf 20021225
#define ll long long
#define N 100010
using namespace std;
int read()
{
	int f=1,s=0; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9')	s=s*10+ch-'0',ch=getchar();
	return f*s;
}
struct edge{int to,lt;}e[N<<1];
int f[N],in[N],cnt,n;
void add(int x,int y)
{
	e[++cnt].to=y; e[cnt].lt=in[x]; in[x]=cnt;
	e[++cnt].to=x; e[cnt].lt=in[y]; in[y]=cnt;
}
void dfs(int x,int fr)
{
	for(int i=in[x];i;i=e[i].lt)
	{
		int y=e[i].to; if(y==fr)	continue;
		dfs(y,x); f[x]^=(f[y]+1);
	}
}
int main()
{
	n=read();
	for(int i=1;i<n;i++)	add(read(),read());
	dfs(1,0); puts(f[1]?"Alice":"Bob");
	return 0;
}