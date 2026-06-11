// IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define int ll
#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ends << H; debug_out(T...); }
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e15;
const ll MOD = 1e9 + 7;
 
////////////////////////////////////////////////////////////////////

const int N = 1e5 + 5, M = 3;

int A[N], DP[N][M];
bool P[N];

int Sign(int i) { return i & 1 ? -1 : 1; }

int32_t main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mt19937 Rnd(time(0));

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) DP[i][j] = -INF;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		if (i) {
			char c; cin >> c;
			P[i] = (c == '+');
		}
		cin >> A[i];
	}
	DP[0][0] = A[0];
	for (int i = 1; i < n; i++) for (int j = M - 1; j >= 0; j--) {
		if (P[i]) DP[i][j] = DP[i - 1][j] + A[i] * Sign(j);
		else if (j) DP[i][j] = DP[i - 1][j - 1] + A[i] * Sign(j);
		if (j + 1 < M) DP[i][j] = max(DP[i][j], DP[i][j + 1]);
	}
	cout << DP[n - 1][0] << endl;

	return 0;
}
