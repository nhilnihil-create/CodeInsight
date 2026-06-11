#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

int f[2];

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  while (n--) {
    int x; cin >> x;
    f[x & 1]++;
  }
  f[0] += f[1] / 2;
  f[0] = min(f[0], 1);
  f[1] %= 2;
  if (f[0] + f[1] <= 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}


