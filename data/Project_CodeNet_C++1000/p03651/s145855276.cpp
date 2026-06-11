#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int gcd(int a, int b) {
  if (a < b) {
    a ^= b;
    b ^= a;
    a ^= b;
  }
  return b ? gcd(b, a % b) : a;
}

int main() {
  int n, k;
  cin >> n >> k;
  int all_gcd;
  int max_num = 0;
  REP(i, n) {
    int t;
    cin >> t;
    if (i == 0) {
      all_gcd = t;
    } else {
      all_gcd = gcd(all_gcd, t);
    }
    max_num = max(max_num, t);
  }
  if (k % all_gcd == 0 && k <= max_num) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}