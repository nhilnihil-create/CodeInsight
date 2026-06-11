//Love and Freedom.
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
#define inf 20021225
#define N 100010
using namespace std;
int read()
{
	int s=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return f*s;
}
struct edge{int to,lt;}e[N];
int in[N],cnt,f[N],tmp[N];
void add(int x,int y)
{
	e[++cnt].to=y; e[cnt].lt=in[x]; in[x]=cnt;
}
void dfs(int x)
{
	if(!in[x])	return; int t=0;
	for(int i=in[x];i;i=e[i].lt)	dfs(e[i].to);
	for(int i=in[x];i;i=e[i].lt)	tmp[++t]=f[e[i].to];
	sort(tmp+1,tmp+t+1);
	for(int i=2;i<=t;i++)	if(tmp[i]<=tmp[i-1])
		tmp[i]=tmp[i-1]+1;
	f[x]=tmp[t]+1;// printf("%d %d\n",x,f[x]);
}
int main()
{
	int n=read(),x;
	for(int i=2;i<=n;i++) x=read(),add(x,i);
	dfs(1); printf("%d\n",f[1]);
	return 0;
}