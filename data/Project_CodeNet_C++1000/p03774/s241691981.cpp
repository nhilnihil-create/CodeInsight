#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const long double PI = acos(-1);
// }}} End Header
ll calc(P p1, P p2){
	ll ans = abs(p1.first -p2.first) + abs(p1.second - p2.second);
	return ans;
}
int main() {
	ll n, m;
	cin >> n >> m;
	vector<P> x(n);
	vector<P> y(m);
	rep(i,n) cin >> x[i].first >> x[i].second;
	rep(i,m) cin >> y[i].first >> y[i].second;
	for(auto k : x){
		ll min = INF, ans;
		rep(i,m){
			ll dist = calc(k, y[i]);
			if(dist < min){
				min = dist;
				ans = i+1;
			}
		}
		cout << ans << endl;
	}
 	return 0;
}