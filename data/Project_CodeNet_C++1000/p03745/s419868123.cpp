#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define INF 9223372036854775807
#define all(x) (x).begin(), (x).end()

ll n, a, b, c, ans, x;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  cin >> a;

  for (int i = 1; i < n; i++) {
    cin >> b;
    if (b == a) continue;

    if (x) {
      if (x == 1 && b < a || x == -1 && b > a) x = 0, c++;
    } else
      x = b > a ? 1 : -1;
    a = b;
  }
  cout << c + 1 << "\n";
}