#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

int main() {
#ifdef LOCAL_EXEC
	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  ll ans = 0;
  ll max_size = 0;
  for (int i = 1; i <= n; i++) {
    ll ai; cin >> ai;
    if (ai > max_size + 1) {
      ans += (ai - 1) / (1 + max_size);
      ai = 1;
    }
    max_size = max(max_size, ai);
  }
  cout << ans << endl;

  return 0;
}
