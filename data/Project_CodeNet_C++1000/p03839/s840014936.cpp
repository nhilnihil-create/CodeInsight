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
int N, K;

signed main() {
  cin >> N >> K;
  vector<ll> a(N), s1(N + 1), s2(N + 1);
  rep(i, N) {
    cin >> a[i];
    s1[i + 1] = s1[i] + a[i];  // s1[i] := a[0]~a[i-1]までの合計
    s2[i + 1] =
        s2[i] +
        max(0ll, a[i]);  // s2[i] := a[0]~a[i-1]のうち0以上の部分だけを加える
  }
  ll res = -INF;
  // 最後に長さKの区間を選び, それを白か黒にする
  // それ以外は自由に決められる
  for (int i = 0; i + K <= N; i++) {
    int left = i,
        right = i + K;  // 長さKの区間の左端と右端+1(累積和から求めるから)
    ll tmp = (s2[left] - s2[0]) +              // 区間外は自由に選べるので非負の累積和
             max(0ll, s1[right] - s1[left]) +  // 今選んでいる長さKの区間のマスを全て黒にするか白にするか
             (s2[N] - s2[right]); // 区間外は自由に選べるので非負の累積和
    res = max(res, tmp);
  }
  cout << res << endl;
  return 0;
}