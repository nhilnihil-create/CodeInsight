#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define reps(i, n) for (int i = 1, i##_len = (int)(n); i <= i##_len; i++)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define repi(i, x) \
	for (auto i = (x).begin(), i##_fin = (x).end(); i != i##_fin; i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a) ? "Yes" : "No")
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int, int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long, long long> P;
typedef vector<P> VP;
template <class T>
inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return 1;
	}
	return 0;
}
const long long INFLL = 1LL << 60;
const int INF         = 1 << 20;
const double PI       = acos(-1);
int main() {
	int n, ma, mb;
	cin >> n >> ma >> mb;
	vector<tuple<int, int, int>> data(n);
	int a, b, c;
	int per;
	int ans = INF;
	rep(i, n) {
		cin >> a >> b >> c;
		data[i] = make_tuple(a, b, c);
	}
	vector<vector<vector<int>>> dp(n + 1, VVi(420, Vi(420, INF)));
	dp[0][0][0] = 0;
	rep(i, n) {
		for (int a = 0; a <= 405; a++) {
			for (int b = 0; b <= 405; b++) {
				if (1) {
					chmin(dp[i + 1][a][b], dp[i][a][b]);
				}

				chmin(dp[i + 1][a + get<0>(data[i])][b + get<1>(data[i])],
				      dp[i][a][b] + get<2>(data[i]));
				/*if (dp[i][a][b] != INF) {
				    clog << i << " " << a << " " << b << "::" << dp[i][a][b]
				         << endl;
				}*/
			}
		}
	}
	for (int i = 1; max(ma, mb) * i < 410; i++) {
		chmin(ans, dp[n][i * ma][i * mb]);
		/*	if (dp[n][ma * i][ma * i] != INF) {
		        clog << n << " " << ma * i << " " << mb * i
		             << "::" << dp[n][ma * i][mb * i] << endl;
		    }*/
	}
	/*
	dp[at][yen]=per(a,b)
	init:(-1,-1), [0][0]=(0,0)
	transsit:[at][yen]=[at-1][yen]
	40*400*400 10^6*64
	dp[at][a][b]=yen
	intit: inf, [0][0][0]=0;
	trinssit; [at][a][b]=min([at-1][a][b],[at-1][a-data][b-data]+data)
	find; at[i][j]; i;j = ma:mb;

	*/
	if (ans == INF) {
		cout << -1 << endl;

		return 0;
	}
	cout << ans << endl;
}