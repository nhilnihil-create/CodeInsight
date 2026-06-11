#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n, m;
	cin >> n >> m;
	vvi dist(n, vi(n, INF));
	vvi e(n, vi(n, INF));
	vi aa(m), bb(m);

	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;b--;
		dist[a][b] = dist[b][a] = c;
		e[a][b] = e[b][a] = c;
		aa[i] = a; bb[i] = b;
	}

	rep(k, n)rep(i, n)rep(j, n)dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int cnt = 0;
	rep(i, m)if (dist[aa[i]][bb[i]] < e[aa[i]][bb[i]])cnt++;
	
	cout << cnt << endl;

}