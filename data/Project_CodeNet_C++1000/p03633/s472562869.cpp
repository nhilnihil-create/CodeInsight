#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
// 返り値: a と b の最大公約数
template <typename T>
ll GCD(T a, T b) {
  if (b == 0) {
    return a;
  }
  ll d = GCD(b, a % b);
  return d;
}
int main() {
  ll N;
  cin >> N;
  vector<ll> T(N);

  REP(i, N) { cin >> T[i]; }
  ll ans = T[0];
  REP(i, N) { ans = (ans) / GCD(ans, T[i]) * T[i]; }
  cout << ans << endl;
}