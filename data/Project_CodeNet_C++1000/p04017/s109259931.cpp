// ****IMP DP PROBLEM****
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define ordered_set tree < ll ,  null_type ,  less<ll> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//added two more functions to set
//(1)*(set.find_by_order(k))[kth element in the sorted set] 
//(2)set.order_of_key(k)[count of elements strictly less than k]
typedef vector< int > vi;
typedef vector< ll > lvi;
typedef vector< vi > vvi;
typedef vector< lvi > lvvi;
typedef pair< int,int > ii;
typedef pair< ll,ll > lii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)//remember i is an iterator
#define present(c,x) ((c).find(x) != (c).end())//for sets,maps,multimaps
#define cpresent(c,x) (find(all(c),x) != (c).end())//for vectors
#define tc(t) int (t); cin>>(t);while((t)--)
#define ff first
#define ss second
#define mp make_pair
#define ld long double
#define ull unsigned long long int
#define mod 1000000007
ll dp[25][100005];
ll n,a[200000];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	ll l;
	cin>>l;
	for(int i=0;i<n;i++)//init
	{
		dp[0][i]=upper_bound(a,a+n,a[i]+l)-a-1;
	}
	for(int k=1;k<=22;k++)
	{
		for(int i=0;i<n;i++)
		{
			dp[k][i]=dp[k-1][dp[k-1][i]];
		}
	}
	tc(T)
	{
		ll x,y;
		cin>>x>>y;
		x--;
		y--;
		if(x>y) swap(x,y);
		ll ans=0;
		for(int k=22;k>=0;k--)
		{
			if(dp[k][x]<y)
			{
				ans+=(1<<k);
				x=dp[k][x];
			}
		}
		cout<<ans+1<<endl;
	} 
	return 0;
}
// we are basically assuming the steps to be k
// then we try to fill the set bits in k
// we compute dp[k][i] which denote the coordinate of the position that we 
// reach if we jump 2^k steps from i
// this way we can say that if kth bit is set or not
// we do this for every bit ...