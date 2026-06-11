#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
constexpr ll MOD = 1e9+7;

int N, seg[4000004] = { 0 }, tmp[4000004] = { 0 }, ans = 0;
inline int fast_mod(int i) { return i >= MOD ? i - MOD : i; }
void pull(int n) { seg[n] = fast_mod(seg[n << 1] + seg[n << 1 | 1]); }
void push(int l, int r, int n) {
	seg[n] = ((ll)(r - l + 1) * tmp[n] + seg[n]) % MOD;
	if (l != r) tmp[n << 1] = fast_mod(tmp[n] + tmp[n << 1]), tmp[n << 1 | 1] = fast_mod(tmp[n] + tmp[n << 1 | 1]);
	tmp[n] = 0;
}
void update_range(int a, int b, int v, int l = 0, int r = -1, int n = 1) {
	if (r == -1) r = N - 1;
	push(l, r, n);
	if (l > b || r < a) return;
	if (l >= a && r <= b) {
		tmp[n] = fast_mod(v + tmp[n]);
		push(l, r, n);
	}
	else {
		int m = (l + r) >> 1;
		update_range(a, b, v, l, m, n << 1), update_range(a, b, v, m + 1, r, n << 1 | 1);
		pull(n);
	}
}
int query(int a, int b, int l = 0, int r = -1, int n = 1) {
	if (r == -1) r = N - 1;
	if (a > b || l > b || r < a) return 0;
	push(l, r, n);
	if (l >= a && r <= b) return seg[n];
	int m = (l + r) >> 1;
	return fast_mod(query(a, b, l, m, n << 1) + query(a, b, m + 1, r, n << 1 | 1));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	update_range(0, 0, 1);
	for (int i = 0; i < N - 1; ++i) {
		int v = query(i, i);
		update_range(i + 1, i + 1, v);
		update_range(i + 3, N - 1, v);
		ans = (((min(i + 2, N - 1) + (ll)(N - 1) * (N - 1)) % MOD) * v + ans) % MOD;
	}
	cout << (ans + (ll)N * query(N - 1, N - 1)) % MOD << '\n';
	/*dp[0] = 1;
	for (int i = 0; i < n - 1; ++i) {
		dp[i + 1] += dp[i];
		for (int j = 2; j <= n; ++j) {
			if (i + j + 1 > n - 1) ans += dp[i];
			else dp[i + j + 1] += dp[i];
		}
		ans += (n - 1) * (n - 1) * dp[i];
	}
	cout << ans + n * dp[n - 1] << '\n';*/
}