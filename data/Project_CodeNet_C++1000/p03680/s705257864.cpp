#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  a[0] = 0;
  rep(i, 0, N) {
    cin >> a[i];
    a[i]--;
  }

  int now = a[0], cnt = 1;
  rep(i, 1, N) {
    if (now == 1) {
      cout << cnt << endl;
      return 0;
    }
    now = a[now];
    cnt++;
  }

  cout << -1 << endl;

  return 0;
}
