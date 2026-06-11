#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#include <set>
#include <queue>
using namespace std;

#define X first
#define Y second
#define Mod 1000000007
#define N 100010
#define M 101

typedef long long ll;

const int INF=1<<30;

vector<int> g[N];
int color[N];
ll c1,p,q;

bool Dfs(int x,int c,int &cnt)
{
	cnt++; color[x]=c; bool flag=true;
	for (int i=0,y;i<g[x].size();i++)
	{
		y=g[x][i];
		if (!color[y] && !Dfs(y,3-c,cnt)) flag=false;
		else if (color[x]==color[y]) flag=false;
	}
	return flag;
}

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	
	int n,m,x,y; scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1;i<=n;i++) if (!color[i])
	{
		int sz=0; 
		bool flag=Dfs(i,1,sz);
		if (sz==1) c1++;
		else
		{
			if (flag) q++;
			else p++;
		}
	}
	ll ans=c1*c1+2*c1*(n-c1)+p*p+2*p*q+2*q*q;
	printf("%lld\n",ans);
	
	return 0;
}