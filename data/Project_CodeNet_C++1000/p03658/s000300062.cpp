#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> l(N);
  rep(i, N) cin >> l[i];
  sort(l.begin(), l.end(), greater<int>());

  int ans = 0;
  rep(i, K) ans += l[i];
  cout << ans << endl;
  return 0;
}