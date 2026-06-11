#include <bits/stdc++.h>
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define out(s) freopen(s, "w", stdout);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 1e6 + 5;
int n, dp[N], pre[N];
void add(int &x, int y) {
	x += y; if (x >= mod) x -= mod;
}
void rem(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}
int mul(int x, int y) {
	return 1ll * x * y % mod;
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	dp[0] = 1;
	dp[1] = n;
	dp[2] = mul(n, n);
	
	fw (i, 0, 3) {
		pre[i] = i ? pre[i - 1] : 0;
		add(pre[i], dp[i]);
	}
	
	fw (i, 3, n + 1) {
		//a1 = 1
		add(dp[i], dp[i - 1]);
		
		//a1 = j, a2 = a3 = ... = a(j + 1) = 1.
		add(dp[i], pre[i - 3]);
//		//j = i to n will make 0.
		int cnt = n - i + 1;
		add(dp[i], cnt);
//		
		
		//a1 >= 2, a2 = a3 >= 2 => Everything is equal to a2 and a3.
		add(dp[i], mul(n - 1, n - 1));
		
		pre[i] = pre[i - 1];
		add(pre[i], dp[i]);
	}
	cout << dp[n];
	return 0;
}