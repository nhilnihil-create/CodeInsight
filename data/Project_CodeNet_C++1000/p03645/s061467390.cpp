#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define sz(x) (int)(x).size();
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int32_t main()
{
	int n=in();int m=in();
	map<int,bool> o,e;
	int u,v;
	for(int i=0;i<m;i++)
	{
		u=in();v=in();
		if(u==1)o[v]=1;
		else if(u==n)e[v]=1;
		if(v==1)o[u]=1;
		else if(v==n)e[u]=1;
	}
	
	bool ok=0;
	for(auto i:o)
	{
		if(e[i.first])ok=1;
	}
	if(ok)puts("POSSIBLE");
	else puts("IMPOSSIBLE");
	
}
