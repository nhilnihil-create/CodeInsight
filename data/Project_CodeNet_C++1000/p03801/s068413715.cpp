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
    ll n, a;
    cin >> n;
    vector<ll> ans(n, 0LL), p;
    vector<pair<ll, ll> > v;
    for(int i=0;i<n;i++){
    	cin >> a;
    	v.push_back({a, i});
    }
    sort(be(v));
    p.pb(0LL);
    for(auto& i:v) p.pb(i.first);
    ll i = n, idx = INF;
    while(i > 0) {
    	ll id = lower_bound(be(p), p[i]) - p.begin();
    	i = id - 1;
    	idx = min(idx, v[i].second);
    	ans[idx] += (n - i) * (p[id] - p[i]);
    }
    for(int i=0;i<n;i++) cout << ans[i] << endl;

    return 0;
}
