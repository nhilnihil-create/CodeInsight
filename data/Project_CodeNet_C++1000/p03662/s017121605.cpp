/////////////////////////////////////////
////////// ^\/^ *_* :) :-D '~' \\\\\\\\\\
/////////////////////////////////////////
#include <bits/stdc++.h>
//#include <algorithm>
//#include <cstdio>
//#include <functional>
#include <iostream>
//#include <cfloat>
//#include <climits>
//#include <cstdlib>
//#include <cstring>
//#include <cmath>
//#include <map>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <string>
//#include <time.h>
//#include <vector>
//#include <random>
//#include <unordered_set>
//#include <complex>
//#include <string.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

int n;
vector <int> g[100010];
int color[100010];

int main()
{
	cin>>n;
	rep(i,n-1)
	{
		int x,y;
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	queue <int> q;
	memset(color,-1,sizeof(color));
	q.push(1);
	color[1]=1;
	q.push(n);
	color[n]=0;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		rep(i,g[t].size())
		{
			if(color[g[t][i]]==-1)
			{
				color[g[t][i]]=color[t];
				q.push(g[t][i]);
			}
		}
	}
	int fen=0,snu=0;
	repn(i,n) if(color[i]==1) fen++;else snu++;
	if(fen>snu) puts("Fennec");
	else puts("Snuke");
	rt0;
}