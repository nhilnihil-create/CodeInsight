
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
	int n=in(),x;
	set<int> s;
	while(n--)
	{
		x=in();
		if(s.find(x)==s.end())s.insert(x);
		else s.erase(x);
	}	
	cout<<s.size();
	
}