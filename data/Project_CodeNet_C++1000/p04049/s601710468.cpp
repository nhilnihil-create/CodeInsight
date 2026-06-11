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

template <class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template <class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vvi g(n);
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if (k & 1) {
		queue<int> q;
		vi d(n);
		int ans = INF;
		REP(i, n) {
			REP(j, g[i].size()) {
				q.push(g[i][j]);
				q.push(i);
				REP(k, n)d[k] = INF;
				d[i] = 0;
				d[g[i][j]] = 0;
				while (!q.empty()) {
					int p = q.front(); q.pop();
					REP(k, g[p].size()) {
						if (chmin(d[g[p][k]], d[p] + 1)) {
							q.push(g[p][k]);
						}
					}
				}
				int cnt = 0;
				REP(i, n) if (d[i] > k / 2)cnt++;
				chmin(ans, cnt);
			}
		}
		cout << ans << endl;
	}
	else {
		queue<int> q;
		vi d(n);
		int ans = INF;
		REP(i, n) {

			q.push(i);
			REP(k, n)d[k] = INF;
			d[i] = 0;
			while (!q.empty()) {
				int p = q.front(); q.pop();
				REP(k, g[p].size()) {
					if (chmin(d[g[p][k]], d[p] + 1)) {
						q.push(g[p][k]);
					}
				}
			}
			int cnt = 0;
			REP(i, n) if (d[i] > k / 2)cnt++;
			chmin(ans, cnt);

		}
		cout << ans << endl;
	}
}