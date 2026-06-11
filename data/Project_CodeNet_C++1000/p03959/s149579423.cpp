#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

const int N = 1e5 + 5;
int a[N], b[N];

const ll mod = 1e9 + 7;

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  ll ans = 1;
  if (a[1] > b[1] || a[n] < b[n] || a[n] != b[1]) ans = 0;
  for (int i = 2; i <= n - 1; i++) {
    if (a[i] == a[i - 1] && b[i] == b[i + 1]) {
      ans = (ans * min(a[i], b[i])) % mod;
    }
    if (a[i] != a[i - 1]) {
      if (b[i] < a[i]) ans = 0;
    }
    if (b[i] != b[i + 1]) {
      if (a[i] < b[i]) ans = 0;
    }
  }

  cout << ans << endl;

  return 0;
}
