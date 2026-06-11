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
int n,dist[100010],dist2[100010];
vector <int> g[100010];

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
	memset(dist,1,sizeof(dist));
	memset(dist2,1,sizeof(dist2));
	queue <int> q;
	dist[1]=0;
	q.push(1);
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		rep(i,g[t].size())
		{
			if(dist[g[t][i]]!=16843009) continue;
			else
			{
				dist[g[t][i]]=dist[t]+1;
				q.push(g[t][i]);
			}
		}
	}
	queue <int> q1;
	dist2[n]=0;
	q1.push(n);
	while(!q1.empty())
	{
		int t=q1.front();
		q1.pop();
		rep(i,g[t].size())
		{
			if(dist2[g[t][i]]!=16843009) continue;
			else
			{
				dist2[g[t][i]]=dist2[t]+1;
				q1.push(g[t][i]);
			}
		}
	}
	int fen=0,snu=0;
	repn(i,n)
	{
		if(dist[i]<=dist2[i]) fen++;
		else snu++;
	}
	if(fen>snu) puts("Fennec");
	else puts("Snuke");
	rt0;
}