// IOI 2021
 
#include <bits/stdc++.h>

using namespace std;

#define int ll
#define endl "\n"
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
#define debugP(p) cerr << #p << ": {" << p.first << ", " << p.second << '}' << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e9;
const int MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 1e5 + 5, LG = 61;

int X[N], Y[N], PAR[LG][N];

int GetPar(int v, ll h) {
	for (int i = 0; i < LG; i++) if ((1LL << i) & h) v = PAR[i][v];
	return v;
}

int32_t main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> X[i];
	for (int i = 0; i < n - 1; i++) Y[i] = X[i + 1] - X[i], PAR[0][i] = i;
	int m; cin >> m;
	ll k; cin >> k;
	for (int i = 0; i < m; i++) {
		int a; cin >> a; a--;
		swap(Y[a - 1], Y[a]);
		swap(PAR[0][a - 1], PAR[0][a]);
	}
	for (int pw = 1; pw < LG; pw++) for (int i = 0; i < n - 1; i++) PAR[pw][i] = PAR[pw - 1][PAR[pw - 1][i]];
	int last = X[0];
	for (int i = 0; i < n - 1; i++) {
		cout << last << endl;
		int p = GetPar(i, k);
		last += X[p + 1] - X[p];
	}
	cout << last << endl;

	return 0;
}