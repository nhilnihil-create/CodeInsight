// IOI 2021
 
#include <bits/stdc++.h>
using namespace std;

#define sync ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
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
const ll INF = 1e9, MOD = 1e6 + 7;
 
/////////////////////////////////////////////////////////////////////
 
const int N = 2e5 + 5, C = 26;

int NXT[N][C], DP[N], PAR[N];

int main() {
 
	sync;

	string s; cin >> s;
	int n = sz(s);

	for (int i = 0; i < N; i++) DP[i] = INF;
	for (int c = 0; c < C; c++) NXT[n][c] = n;
	for (int i = n - 1; i >= 0; i--) {
		for (int c = 0; c < C; c++) NXT[i][c] = NXT[i + 1][c];
		NXT[i][s[i] - 'a'] = i;
	}
	DP[n + 1] = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int c = 0; c < C; c++) if (DP[i] > DP[NXT[i][c] + 1] + 1) {
			DP[i] = DP[NXT[i][c] + 1] + 1;
			PAR[i] = c;
		}
	}
	for (int i = 0; i < n; i = NXT[i][PAR[i]] + 1) cout << (char)('a' + PAR[i]);
	cout << endl;

	return 0;
}
