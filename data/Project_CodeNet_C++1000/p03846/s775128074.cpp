#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
int n;
int A[N];

ll power(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int j;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> j;
    ++A[j];
  }

  bool ok = true;
  if (n & 1) {
    if (A[0] != 1) ok = false;
    for (int i = 2; i <= n - 1; i += 2) {
      if (A[i] != 2) {
        ok = false;
        break;
      }
    }
    if (ok)
      cout << power(2, (n - 1) / 2) << endl;
    else
      cout << 0 << endl;
  } else {
    for (int i = 1; i <= n - 1; i += 2) {
      if (A[i] != 2) {
        ok = false;
        break;
      }
    }
    if (ok)
      cout << power(2, n / 2) << endl;
    else
      cout << 0 << endl;
  }

  return 0;
}
