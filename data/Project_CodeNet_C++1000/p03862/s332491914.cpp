#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  ll N, x;
  cin >> N >> x;
  ll ans = 0;
  ll a1, a2 = 0;
  cin >> a1;
  if (a1 > x) {
    ans += a1 - x;
    a1 = x;
  }
  REP(i, N - 1) {
    cin >> a2;
    if (a1 + a2 > x) {
      ans += a1 + a2 - x;
      a2 = x - a1;
    }
    a1 = a2;
  }
  cout << ans << endl;
}