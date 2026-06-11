#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()

constexpr auto INF = INT_MAX/2;
constexpr auto MOD = 1000000007;

int n, m, r;
vvi road;

int main() {

	cin >> n >> m >> r;
	vi vis(r);
	rep(i, r) {
		cin >> vis[i];
		vis[i]--;
	}
	sort(all(vis));

	road.assign(n, vi(n, INF));

	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		road[a][b] = c;
		road[b][a] = c;
	}

	rep(k, n)rep(i, n)rep(j, n)road[i][j] = min(road[i][j], road[i][k] + road[k][j]);
	
	int ans = INF;

	do {
		int len = 0;
		rep(i, r - 1)len += road[vis[i]][vis[i + 1]];
		ans = min(ans, len);

	} while (next_permutation(all(vis)));

	cout << ans << endl;

}