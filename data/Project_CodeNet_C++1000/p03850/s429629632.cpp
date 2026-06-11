#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

vector<ll> dq;
vector<ll> S;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	dq.pb(0); S.pb(0);
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		char c='+';
		if(i>0) 
		{
			cin>>c;
		}
		ll x; cin>>x;
		sum+=x;
		if(c=='+')
		{
			S.back()+=x;
		}
		else
		{
			S.pb(0);
			dq.pb(x);
		}
	}
	if(dq.size()==1)
	{
		cout<<sum<<'\n';
		return 0;
	}
	ll ans = -ll(1e18);
	for(int i=1;i<S.size();i++)
	{
		ans=max(ans, sum - 2LL*(S[i]+dq[i]));
		sum-=2LL*dq[i];
	}
	ans = max(ans, sum);
	cout<<ans<<'\n';
}
