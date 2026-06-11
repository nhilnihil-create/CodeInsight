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
	int n;
	cin >> n;
	vi x(n);
	REP(i, n)cin >> x[i];
	int l; cin >> l;

	vvi v(n, vi(20));
	REP(i, n) {
		int c = upper_bound(ALL(x), x[i] + l) - x.begin();
		v[i][0] = c - 1;
	}
	FOR(j,1, 20) {
		REP(i, n) {
			int k = v[i][j - 1];
			if (k == n)v[i][j] = n;
			else {
				v[i][j] = v[v[i][j - 1]][j - 1];
			}
		}
	}
	int q; cin >> q;

	REP(i, q) {
		int l = 0, r = n;
		int a, b;
		cin >> a >> b; a--; b--;

		if (a > b)swap(a, b);
		while (r - l > 1) {
			int mid = (r + l) / 2;
			int p = a;
			REP(i, 20) {
				if (p == n)break;
				if ((1 << i) & mid) {
					p = v[p][i];
				}
			}
			if (p >= b)r = mid;
			else l = mid;
		}
		cout << r << endl;
	}
}