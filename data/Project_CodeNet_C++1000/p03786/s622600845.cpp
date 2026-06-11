#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
const int N=1e5+4;
int a[N];
int32_t main()
{
	int n=in();
	for(int i=1;i<=n;i++)a[i]=in();
	sort(a+1,a+n+1);
	
	int cur=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(sum*2<a[i+1])cur=i;
	}
	cout<<n-cur;
}
