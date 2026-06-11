#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  ll i, o, t, j, l, s, z;
  cin >> i >> o >> t >> j >> l >> s >> z;
  // 使うのはi, o, j, lのみ
  ll ans = (i / 2 + j / 2 + l / 2) * 2;
  if (i && j && l) {
    ans = max(ans, ((i - 1) / 2 + (j - 1) / 2 + (l - 1) / 2) * 2 + 3);
  }
  ans += o;
  cout << ans << endl;
  return 0;
}