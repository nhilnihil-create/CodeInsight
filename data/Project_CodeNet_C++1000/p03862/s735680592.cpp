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
	int n=in();int x=in();
	vector<int> a(n);
	trav(i,a)i=in();
	int ans=0;
	if(a[0]>x){ans+=a[0]-x;a[0]=x;}
	for(int i=0;i<n-1;i++)
	{
		if(a[i]+a[i+1]>x)
		{
			int d=a[i+1]+a[i]-x;
			a[i+1]-=d;
			ans+=d;
		}
	}
	cout<<ans;
	
}