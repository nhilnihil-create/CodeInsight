#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
  int n; cin >> n;
  vector<pair<ll, ll> > v(1);
  cin >> v[0].fi, v[0].se = v[0].fi;
  rep(i, 1, n) {
  	char op; int a; cin >> op >> a;
  	if (op == '+') v.back().se += a;
  	else v.pb({a, a});
	}
	//rep(i, 0, sz(v)) cout << v[i].fi << " " << v[i].se << endl;
	ll ans = -LLONG_MAX, drop = 0, sum = 0;
	rep(i, 0, sz(v)) sum += v[i].se;
	rep(i, 1, sz(v)) {
		ans = max(ans, sum - drop * 2- v[i].se * 2);
		drop += v[i].fi;
	}
	ans = max(ans, sum - drop * 2);
	cout << ans;
	return 0;
}