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
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 2e3 + 5;

int A[N], DP[N];

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, x; cin >> n >> x;
	ll ans = INF * INF;
	for (int i = 0; i < n; i++) cin >> A[i], DP[i] = A[i];
	for (int i = 0; i < n; i++) {
		ll sum = 1LL * i * x;
		for (int j = 0; j < n; j++) DP[j] = min(DP[j], A[(j - i + n) % n]), sum += DP[j];
		ans = min(ans, sum);
	}
	cout << ans << endl;

	return 0;
}
