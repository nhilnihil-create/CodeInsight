#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<int> a(N + 1);
  a[0] = 0;
  rep(i, 0, N) cin >> a[i + 1];

  int current = a[1], cnt = 1;
  rep(i, 2, N + 1) {
    if (current == 2) {
      cout << cnt << endl;
      return 0;
    }
    current = a[current];
    cnt++;
  }

  cout << -1 << endl;

  return 0;
}
