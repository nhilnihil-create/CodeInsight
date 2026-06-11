	#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

const int N = 2e5 + 10;
int a[N], dp[N], nxt[N];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
  	cin >> a[i];
  }
  vector<pair<int, int>> st;
  int ans = 0;
  for (int i = n; i >= 1; i--) {
  	while (!st.empty() && st.back().F > a[i]) {
  		st.pop_back();
  	}
  	if (!st.empty()) {
  		nxt[i] = st.back().S;
  	}
  	st.pb({a[i], i});
  	if (nxt[i] == 0) {
  		dp[i] = (n - i + 1) * a[i];
  	}
  	else {
  		dp[i] = (nxt[i] - i) * a[i] + dp[nxt[i]];
  	}
  	ans += dp[i];
  }
  cout << ans << '\n';
}