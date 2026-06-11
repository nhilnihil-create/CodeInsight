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
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll m,n; cin>>m>>n;
	ll ans=0;
	vector<pair<ll,int> > vec;
	for(int i=0;i<m;i++)
	{
		ll x; cin>>x;
		vec.pb(mp(x,0));
	}
	for(int i=0;i<n;i++)
	{
		ll x; cin>>x;
		vec.pb(mp(x,1));
	}
	sort(vec.begin(),vec.end());
	ll R = n + 1; ll C = m + 1;
	for(int i=0;i<vec.size();i++)
	{
		ll cost=vec[i].fi; ll ty=vec[i].se; 
		if(ty==0)
		{
			ans+=R*cost;
			C--;
		}
		else
		{
			ans+=C*cost;
			R--;
		}
	}
	cout<<ans<<'\n';
}
