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
	map<int,int> a;
	int x,t;
	int n=in();int k=in();
	for(int i=0;i<n;i++)
	{
		x=in();t=in();
		a[x]+=t;
	}
	vector<pair<int,int>> f;
	trav(i,a)f.push_back({i.first,i.second});
	int i=0;
	while(k>0)
	{
		if(f[i].second<k)k-=f[i].second;
		else if(f[i].second>=k){cout<<f[i].first;return 0;}
		i++;
		
	}
	
}