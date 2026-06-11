#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define all(obj) (obj).begin(), (obj).end()
static const int dx[4] = {0, 1, 0, -1};
static const int dy[4] = {1, 0, -1, 0};
static const char dir[4] = {'u', 'r', 'd', 'l'};
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;
int N;

signed main() {
  cin >> N;
  vector<int> p(N), a(N), b(N);
  rep(i, N) {
    cin >> p[i];
    --p[i];
  }
  int aim = 30000;
  rep(i, N) {
    a[i] = 1 + aim * i;
    b[i] = 1 + aim * (N - i + 1);
  }
  rep(i, N) { a[p[i]] += i; }

  rep(i, N) {
    if (i) {
      cout << " ";
    }
    cout << a[i];
  }
  cout << endl;
  rep(i, N) {
    if (i) {
      cout << " ";
    }
    cout << b[i];
  }
  cout << endl;
  return 0;
}