#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#define inf 20021225
#define ll long long
#define mxn 2010
#define mp make_pair
#define fs first
#define se second
#define pa pair<int,int>
using namespace std;
 
struct edge{int to,lt;}e[mxn<<1];
int f[mxn][mxn],in[mxn],cnt,d[mxn];
int n,k;bool del[mxn];
set<pa> st;
void add(int x,int y)
{
	e[++cnt].to=y;e[cnt].lt=in[x];in[x]=cnt;
	e[++cnt].to=x;e[cnt].lt=in[y];in[y]=cnt;
}
 
void dfs(int x,int fa,int rt)
{
	for(int i=in[x];i;i=e[i].lt)
	{
		int y=e[i].to;if(y==fa) 	continue;
		f[rt][y]=f[rt][x]+1; dfs(y,x,rt);
	}
}
 
void getdis()
{
	for(int i=1;i<=n;i++)	dfs(i,i,i);
}
 
void work()
{
	int ans=0,x,tmp;	getdis();
	for(int i=1;i<=n;i++)
	{
		tmp=0; if(d[i]!=1)	continue;
		for(int j=1;j<=n;j++)
			if(f[i][j]>k)	tmp++;
		st.insert(mp(tmp,i));
	}
	while(!st.empty())
	{
		set<pa>::iterator it=--st.end(); pa mx=*it;
		if(mx.fs<=0)	break;
		del[mx.se]=1; st.erase(it);	x=mx.se;
		for(it=st.begin();it!=st.end();it++)
		{
			pa cur=*it; int y=cur.se;
			if(f[x][y]>k)
				st.erase(it),st.insert(mp(cur.fs-1,y));
		}
		for(int i=in[x];i;i=e[i].lt)
		{
			int y=e[i].to; d[y]--;// printf("%d %d\n",y,d[y]);
			if(d[y]==1)
			{
				tmp=0;
				for(int j=1;j<=n;j++)
					if(!del[j]&&f[y][j]>k)	tmp++;
				st.insert(mp(tmp,y));
			}
		}
		ans++;
	}
	printf("%d\n",ans);
}
 
int main()
{
	int x,y;
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)	scanf("%d%d",&x,&y),add(x,y),d[x]++,d[y]++;
	work();
	return 0;
}
