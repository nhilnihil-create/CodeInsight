
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
int lcm(int a,int b)
{
	if(a<b)swap(a,b);
	a/=__gcd(a,b);
	return a*b;
}
int32_t main()
{
	int n=in();
	vector<int> a(n);
	trav(i,a)i=in();sort(all(a));
	int ans=1;
	
	for(auto i:a)
	{
		ans=lcm(ans,i);
	}
	cout<<ans;
	
	
}