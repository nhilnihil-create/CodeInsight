#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, L, t;
    cin >> n >> L >> t;
    ll x[n], w[n];
    vector<ll> v;
    ll id = -1;
    for(int i=0;i<n;i++){
    	cin >> x[i] >> w[i];
    	if(w[i] == 1) id = i;
    }
    if(id == -1){
    	for(int i=0;i<n;i++){
    		cout << ((x[i] - t) % L + L) % L << endl;
    	}
    	return 0;
    }
    ll num = id;
    ll a = (x[id] + t) % L;

    for(int i=0;i<n;i++){
    	if(w[i] == 1){
    		v.pb((x[i] + t) % L);
    	}
    	if(w[i] == 2){
    		v.pb(((x[i] - t) % L + L)%L);
    		ll b = x[id] - x[i];
    		b += L;
    		b %= L;
    		num += (t * 2 + b) / L;
    		num %= n;
    	}
    }
    sort(be(v));
    vector<ll> ans(n);
    id = upper_bound(be(v), a) - v.begin() - 1;
    for(int i=id;i<n+id;i++, num++){
    	num %= n;
    	ans[num] = v[i % n];
    }
    for(int i=0;i<n;i++){
    	cout << ans[i] << endl;
    }
    return 0;
}
