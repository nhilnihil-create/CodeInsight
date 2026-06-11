#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
#define N 2010
int n,k,d[N];
vector<int> v[N];
struct point{
	int x,y;
}e[N];
void dfs(int x,int last)
{
	for(int i=0,y;i<v[x].size();i++)
	{
		y=v[x][i];
		if(y==last) continue;
		d[y]=d[x]+1;
		dfs(y,x);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1,a,b;i<=n-1;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
		e[i].x=a,e[i].y=b;
	}
	int ans=N;
	if(k&1)
	{
		int tep;
		for(int i=1,x,y;i<n;i++)
		{
			tep=0;
		 	x=e[i].x,y=e[i].y;
		 	d[x]=d[y]=0;
		 	dfs(x,y),dfs(y,x);
		 	for(int j=1;j<=n;j++)
		 		if(d[j]>k/2) tep++;
		 	ans=min(ans,tep);
		}
	}
	else
	{
		int tep;
		for(int i=1;i<=n;i++)
		{
			tep=0;
		 	d[i]=0;
		 	dfs(i,0);
		 	for(int j=1;j<=n;j++)
		 		if(d[j]>k/2) tep++;
		 	ans=min(ans,tep);
		}	
	}
	printf("%d\n",ans);
}