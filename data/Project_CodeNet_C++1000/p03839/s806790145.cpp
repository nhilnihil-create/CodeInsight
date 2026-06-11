#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<ll(n);++i)
#define RREP(i,n) for(ll i=ll(n)-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<ll(n);++i)
#define RFOR(i,m,n) for(ll i=ll(n)-1;i>=ll(m);--i)
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

constexpr int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
constexpr int dy[8] = { 0,1,1,1,0,-1,-1,-1 };


using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <class T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }
template <class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vl v(n);
	REP(i, n)cin >> v[i];
	vl a(n + 1);
	REP(i, n)a[i + 1] = a[i] + v[i];
	ll ans = 0;
	vl l(n + 1), r(n + 1);
	REP(i, n) {
		l[i + 1] = l[i] + max(0ll, v[i]);
	}
	RREP(i, n) {
		r[i] = r[i + 1] + max(0ll, v[i]);
	}
	REP(i, n-k+1) {
		chmax(ans, max(0ll, a[i + k] - a[i]) + l[i] + r[i + k]);
	}
	cout << ans << endl;
}