#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll h, w, n;
	cin >> h >> w >> n;
	ll sum = (h - 2) * (w - 2);
	vector<ll> ans(10, 0);
	map<pll, int> m;
	REP(i, n) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		for(ll da = -1; da <= 1; da++) {
			for(ll db = -1; db <= 1; db++) {
				ll na = a + da, nb = b + db;
				if(na > 0 && na < h - 1 && nb > 0 && nb < w - 1) m[pll(na, nb)]++;
			}
		}
	}
	ans[0] = sum - (ll)m.size();
	for(auto x: m) {
		ans[x.second]++;
	}
	REP(i, 10) cout << ans[i] << endl;
	return 0;
}
/* --------------------------------------- */
