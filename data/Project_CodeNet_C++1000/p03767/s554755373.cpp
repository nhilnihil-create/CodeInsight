#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll a[3*N];
  ll ans = 0;
  for (int i = 0; i < 3*N; i++) {
    cin >> a[i];
  }
  sort(a,a+(3*N));
  reverse(a,a+(3*N));
  for (int i = 0; i < N; i++) {
    ans += a[(2*i) + 1];
  }
  cout << ans << endl;
  return 0;
}