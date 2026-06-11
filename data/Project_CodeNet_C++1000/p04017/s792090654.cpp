#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
// typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define ll long long 
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
#define lpri(n) printf("%lld",n)
#define pri(n) printf("%d",n)
#define pln() printf("\n")
#define priln(n) printf("%d\n",n)
#define lpriln(n) printf("%lld\n",n)
#define rep(i,init,n) for(int i=init;i<n;i++)
#define pb push_back     
#define mp make_pair
#define F first
#define S second
#define gcd __gcd
#define inf INT_MAX
#define ninf INT_MIN   
#define linf LLONG_MAX
#define lninf LLONG_MIN   
const ll mod=1e9+7;
const int N=1e5+4;

int main()
{
	int n; scn(n);

	int a[n];

	rep(i,0,n)
	scn(a[i]);

	int L; scn(L);

	int dp[n][21];

	for(int i=n-1;i>=0;i--)
	{
		int ind = upper_bound(a,a+n,a[i]+L) - a; ind--;

		dp[i][0] = ind;

		// cout<<i<<" "<<ind<<endl;

		for(int j=1;j<21;j++)
		dp[i][j] = dp[dp[i][j-1]][j-1];
	}

	int q; scn(q);

	// cout<<dp[0][1]<<endl;

	while(q--)
	{
		int x,y; scn(x); scn(y); x--; y--;

		if(x > y)
		swap(x,y);

		int cur = x,ans = 0;

		for(int i=20;i>=0;i--)
		if(dp[cur][i] < y)
		cur = dp[cur][i], ans+=(1<<i);

		ans++;

		priln(ans);
	}

	return 0;
}
