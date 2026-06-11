#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
vector<vector<ll> > v;
ll dfs(ll now){
	vector<ll> d;
	for(auto& to: v[now]){
		d.pb(dfs(to));
	}
	ll ret = 0;
	sort(be(d));
	reverse(be(d));
	ll idx = 1;
	for(auto& i: d){
		ret = max(ret, idx + i);
		idx++;
	}
	return ret;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, a;
    cin >> n;
    v.resize(n);
    for(int i=1;i<n;i++){
    	cin >> a;
    	v[a-1].pb(i);
    }
    cout << dfs(0) << endl;
    return 0;
}
