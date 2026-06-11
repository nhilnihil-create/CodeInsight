#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mtv(kit) cout<<#kit<<" - "<<kit<<"\n";
#define ff first
#define ss second
#define pb push_back
#define rep(i,a,b) for(i=a;i<b;i++)
#define pii pair<ll , ll>
#define all(x) x.begin(),x.end()
#define nl "\n"
#define ump unordered_map

void doit(){	
	ll n, i;
	cin >> n;
	vector<ll>v(n);
	for(i = 0; i < n; i++)cin >> v[i];
	sort(all(v));
	vector<ll>ans;
	for(i = n - 1; i >= 1; i--){
		if(v[i] == v[i - 1]){
			ans.pb(v[i]);
			i--;
		}
	}
	ans.pb(0),ans.pb(0);
	cout << ans[0] * ans[1] << nl;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input1.txt","r",stdin);
//    freopen("output1.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
	// cin >> t;
    for(ll i = 1; i <= t; i++){
        doit();
    }
}
