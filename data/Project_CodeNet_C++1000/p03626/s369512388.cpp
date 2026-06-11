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
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1;
  cin >> s2;
  bool t = s1[0] == s2[0];
  ll ans = t ? 3 : 6;
  int i = t ? 1 : 2;
  for (; i < n;) {
    if (t) {
      if (s1[i] == s2[i]) {
        ans *= 2;
        ans %= MOD;
        i++;
      } else {
        ans *= 2;
        ans %= MOD;
        i += 2;
        t = false;
      }
    } else {
      if (s1[i] == s2[i]) {
        i++;
        t = true;
      } else {
        ans *= 3;
        ans %= MOD;
        i += 2;
      }
    }
  }
  cout << ans << endl;
  return 0;
}