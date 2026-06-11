#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef long long LL;
int read()
{
    char c=getchar();int f=1,sum=0;
    while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0' && c<='9'){sum=sum*10+c-'0';c=getchar();}
    return sum*f;
}
int n;
int head[maxn],to[maxn<<1],nex[maxn<<1],cnt;
void add(int u,int v){to[++cnt]=v;nex[cnt]=head[u];head[u]=cnt;}
int dfs(int x,int fa)
{
	int sg=0;
	for(int i=head[x];i;i=nex[i])
	if(to[i]!=fa) sg^=(dfs(to[i],x)+1);
	return sg;
}
int main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	if(dfs(1,0)) puts("Alice");
	else puts("Bob");
	return 0;
}
