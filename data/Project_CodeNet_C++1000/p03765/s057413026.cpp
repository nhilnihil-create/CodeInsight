#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

string S, T;
int n, m, q, cnts[N], cntt[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> S >> T;
  n = S.length();
  m = T.length();
  for (int i = 1; i <= n; ++i) cnts[i] = (cnts[i - 1] + ((S[i - 1] == 'A') ? 1 : 2)) % 3;
  for (int i = 1; i <= m; ++i) cntt[i] = (cntt[i - 1] + ((T[i - 1] == 'A') ? 1 : 2)) % 3;
  cin >> q;
  while (q--) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    if ((cnts[b] - cnts[a - 1] + 3) % 3 == (cntt[d] - cntt[c - 1] + 3) % 3)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}