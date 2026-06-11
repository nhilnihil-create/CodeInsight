/***********************
*  Author: xuziyuan    * 
***********************/

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++)
#define LL long long
#define pii pair <int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

int n,m,q,qu[100010][3],most[100010],co[100010];
vector <int> g[100010];

void bfs(int da[])
{
	if(da[1]<=most[da[0]]) return;
	most[da[0]]=da[1];
	vector <int> q;
	q.push_back(da[0]);
	rep(i,q.size())
	{
		//if(da[2]==2) cout<<q[i]<<endl;
		int t=q[i];
		if(co[t]==0) co[t]=da[2];
		if(most[t]==0) continue;
		rep(j,g[t].size())
		{
			int to=g[t][j];
			if(most[to]>=most[t]-1) continue;
			most[to]=most[t]-1;
			q.push_back(to);
		}
	}
}

int main()
{
	memset(most,-1,sizeof(most));/*要都清成-1因为输入的距离有可能为0，如果初值为0，
	距离为0时出发点就不会被涂色，因为>=，就错了*/
	cin>>n>>m;
	rep(i,m)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);
	}
	cin>>q;
	rep(i,q) scanf("%d%d%d",&qu[i][0],&qu[i][1],&qu[i][2]);
	for(int i=q-1;i>=0;i--) bfs(qu[i]);
	repn(i,n) cout<<co[i]<<endl;
	rt0;
}