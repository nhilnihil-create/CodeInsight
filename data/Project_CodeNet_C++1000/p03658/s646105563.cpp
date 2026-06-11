#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  int N, K;
  cin >> N >> K;
  int a[100];
  int ans = 0;
  FOR(i, 0, N) cin >> a[i];
  sort(a, a+N, greater<int>());
  FOR(i, 0, K) ans += a[i];
  cout << ans << endl;
  return 0;
}