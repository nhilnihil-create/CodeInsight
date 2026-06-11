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
ll N, A, B, C, D;

signed main() {
  cin >> N >> A >> B >> C >> D;

  // 初期値を0とする
  B -= A;
  A -= A;

  // x回の操作で正に足すと値は[Cx, Dx]の範囲と成る
  // x回の操作で負に足すと値は[D(N-x-1), C(N-x-1)]の範囲となる
  rep(i, N) {
    ll rest = N - (i + 1);
    // [small1, large1]
    ll small1 = C * i;
    ll large1 = D * i;
    // [small2, large2]
    ll small2 = C * rest;
    ll large2 = D * rest;
    if (small1 - large2 <= B && B <= large1 - small2) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}