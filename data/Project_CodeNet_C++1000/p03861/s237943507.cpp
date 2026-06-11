
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
	
	int a=in();int b=in();int x=in();
	a=(a+x-1)/x;a*=x;
	b/=x;b*=x;
	//cout<<a<<" "<<b<<"\n";
	int ans=max(0LL, (b/x-a/x)+1);
	cout<<ans;
}