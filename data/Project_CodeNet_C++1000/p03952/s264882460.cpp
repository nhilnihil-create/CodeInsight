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
ll N, x;

signed main() {
  cin >> N >> x;
  int arr[2 * N];
  for (int i = 1; i < 2 * N; i++) {
    arr[i] = -1;
  }

  if (x <= 1 || x >= 2 * N - 1) {
    puts("No");
    return 0;
  } else {
    puts("Yes");
  }
  arr[N - 1] = 1;
  arr[N] = x;
  arr[N + 1] = N * 2 - 1;
  int iter = 0;
  for (int i = 2; i < 2 * N - 1; i++) {
    if (i == x) continue;
    while (arr[iter] != -1) ++iter;
    arr[iter] = i;
  }
  for (int i = 1; i < 2 * N; i++) {
    cout << arr[i] << endl;
  }
  return 0;
}