#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define INF 9223372036854775807
#define all(x) (x).begin(), (x).end()

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string n, m;

  cin >> n;

  m = n;

  reverse(all(n));

  cout << (n == m ? "Yes" : "No");
}