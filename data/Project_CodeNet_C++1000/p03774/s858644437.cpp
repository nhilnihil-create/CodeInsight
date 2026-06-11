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
ll calc(ll x1, ll y1, ll x2, ll y2){
	return abs(x1-x2)+abs(y1-y2);
}
int main() {
	ll n, m;
	cin >> n >> m;
	vector<P> x(n);
	vector<P> y(m);
	rep(i,n){
		ll a, b; cin >> a >> b;
		x[i].first = a;
		x[i].second = b;
	}
	rep(i,m){
		ll c, d; cin >> c >> d;
		y[i].first = c;
		y[i].second = d;
	}
	for(auto k : x){
		ll min = INF, ans;
		rep(i,m){
			ll dist = calc(k.first, k.second, y[i].first, y[i].second);
			if(dist < min){
				min = dist;
				ans = i+1;
			}
			//cout << ans << " ";
		}
		//cout << endl;
		cout << ans << endl;
	}
 	return 0;
}