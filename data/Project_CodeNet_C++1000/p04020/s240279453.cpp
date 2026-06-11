#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int n;
  cin >> n;
  vector<ll> data(n);
  ll ans = 0;
  REP(i, n) { cin >> data[i]; }
  ll tmp = 0;
  REP(i, n) {
    if (data[i] == 0) {
      ans += tmp / 2;
      tmp = 0;
    } else {
      tmp += data[i];
    }
  }
  ans += tmp / 2;
  cout << ans << endl;
}