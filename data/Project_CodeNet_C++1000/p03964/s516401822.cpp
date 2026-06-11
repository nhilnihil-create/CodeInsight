#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 1e9;

int main() {
  ll n, t, a, nt = 1, na = 1, p;
  cin >> n;

  rep(i, n) {
    cin >> t >> a;
    p = max(ceil(nt / (ld)t), ceil(na / (ld)a));
    nt = t * p;
    na = a * p;
  }

  cout << nt + na << endl;

  return 0;
}
