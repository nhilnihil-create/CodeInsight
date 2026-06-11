#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
#define ll long long
using namespace std;
signed main(){
	vector< pair<ll,ll> > v;
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll x;
		cin>>x;
		v.pb( mp(x,i) );
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	v.pb(mp(0,0));
	vector<ll> a;
	for(ll i=0;i<=n;i++){
		a.pb(0);
	}
	priority_queue<ll> que;
	for(ll i=0;i<n;i++){
		que.push( -v[i].second );
		ll idx = -que.top();
		a[idx] += (v[i].first-v[i+1].first) * (i+1);
	}
	for(ll i=1;i<=n;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}