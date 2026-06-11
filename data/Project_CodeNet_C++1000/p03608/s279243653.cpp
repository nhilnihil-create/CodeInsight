#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define INF 1000000000

ll N, M, R;
int r[9];
int res;
bool used[9];

// 最短経路問題
#define FROM 201
#define TO 201
#define COST INF
int d[FROM][TO];
void warshall_floyd(ll n) {
	rep1(k, n) {			// 経由する頂点
		rep1(i, n) {		// 始点
			rep1(j, n) {	// 終点
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

void dfs(int c, int las, int dist) {
	if (c == R + 1)
	{
		if (res > dist) res = dist;
		return;
	}
	for (int i = 1; i <= R; i++) if (!used[i])
	{
		used[i] = true;
		if (las == -1) dfs(c + 1, i, 0);
		else dfs(c + 1, i, dist + d[r[las]][r[i]]);
		used[i] = false;
	}
}

void solve_abc_d() {
	ll ans = 0;

	cin >> N >> M >> R;

	rep(i, FROM)rep(j, TO) {
		if (i != j) {
			d[i][j] = COST;
		}
	}

	rep1(i, R) {
		cin >> r[i];
	}

	ll a, b, c;
	rep(i, M) {
		cin >> a >> b >> c;
		if (d[a][b] > c) {
			d[a][b] = c;
			d[b][a] = c;
		}
	}

	warshall_floyd(N);

	res = INF;
	dfs(1, -1, 0);
	ans = res;

	cout << ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc_d();

	return 0;
}
