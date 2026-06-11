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
string s;
lvi v;
// lvvi dp;
ll n,y,dp[200000][5];
ll recurs(int idx,int state)
{
	if(idx>=n-1) return 0LL;
	if(dp[idx][state]!=((ll)-1e15)) return dp[idx][state];
	if(s[idx]=='-')
	{
		if(state==0)
		{
			dp[idx][state]=max(recurs(idx+1,state)-v[idx],recurs(idx+1,state+1)-v[idx]);
		}
		if(state==1)
		{

			dp[idx][state]=max(recurs(idx+1,state-1)+v[idx],max(recurs(idx+1,state)+v[idx],recurs(idx+1,state+1)+v[idx]));
		}
		if(state==2)
		{

			dp[idx][state]=max(recurs(idx+1,state)-v[idx],recurs(idx+1,state-1)-v[idx]);
		}
	}
	else
	{
		if(state==0)
		{
			dp[idx][state]=recurs(idx+1,state)+v[idx];
		}
		if(state==1)
		{

			dp[idx][state]=max(recurs(idx+1,state-1)-v[idx],recurs(idx+1,state)-v[idx]);
		}
		if(state==2)
		{
			
			dp[idx][state]=max(recurs(idx+1,state)+v[idx],recurs(idx+1,state-1)+v[idx]);
		}
	}
	// cout<<idx<<" "<<state<<" "<<dp[idx][state]<<endl;
	return dp[idx][state];
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
	cin>>n>>y;
	// dp.assign(n+2,lvi(4,-1e15));
	for(int i=0;i<(n+2);i++)
	{
		for(int j=0;j<5;j++)
		{
			dp[i][j]=-1e15;
		}
	}
	for(int i=1;i<n;i++)
	{
		char ch;
		cin>>ch;
		ll x;
		cin>>x;
		s.pb(ch);
		v.pb(x);
	}
	ll ans=recurs(0,0)+y;
	cout<<ans<<endl;
	return 0;
}