#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define INF 9223372036854775807
#define all(x) (x).begin(), (x).end()

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll a, b;

  cin >> a >> b;

  if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) {
    cout << "Possible"
         << "\n";
  } else {
    cout << "Impossible"
         << "\n";
  }
}