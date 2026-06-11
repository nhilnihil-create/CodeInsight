// IOI 2021
#include <bits/stdc++.h>
using namespace std;

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
const ll INF = 2e9;
const ll MOD = 1e9 + 7;
 
////////////////////////////////////////////////////////////////////

const int N = 1e6 + 5;

int DP[N], PS[N];

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mt19937 Rnd(time(0));

	int n, sum; cin >> n;
	DP[0] = DP[1] = 1;
	sum = DP[0] + DP[1];
	for (int i = 2; i < n; i++) {
		DP[i] = (sum - DP[i - 2] + MOD) % MOD;
		sum = (sum + DP[i]) % MOD;
	}
	int ans = 1LL * sum * (n - 1) % MOD;
	for (int i = 1; i + 1 <= n; i++) ans = (ans + 1LL * DP[i - 1] * (1LL * (n - 1) * (n - 1) % MOD) % MOD) % MOD;
	cout << ans + 1 << endl;

	return 0;
}
