#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<int> cnt;

void solve();

int main() {
  cin >> n >> m;
  cnt.assign(n + 1, 0);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    ++cnt[a], ++cnt[b];
  }
  bool res = 1;
  for (int i = 1; i <= n; ++i) res &= !(cnt[i] & 1);
  if (res)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
