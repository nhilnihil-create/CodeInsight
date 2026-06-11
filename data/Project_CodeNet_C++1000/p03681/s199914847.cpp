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
const int mod=1e9+7;
int32_t main()
{
	int n=in();int m=in();
	if(abs(m-n)>1){cout<<0;return 0;}
	
	int nf=1;for(int i=1;i<=n;i++){nf*=i;nf%=mod;}
	int mf=1;for(int i=1;i<=m;i++){mf*=i;mf%=mod;}
	if(n==m){nf*=2;nf%=mod;}
	cout<<(nf*mf)%mod;
	
	
}