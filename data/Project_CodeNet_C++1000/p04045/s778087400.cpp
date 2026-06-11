#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;

const long double EPS = 1e-10;
const long long INF = 1e18;
const int MOD = (int)1e9 + 7;
const long double PI = acos(-1.0L);

vector<bool> D(10, false);
int main() {
  int n, k;
  cin >> n >> k;

  rep(i, k) {
    int d;
    cin >> d;
    D[d] = true;
  }

  for (int i = n; i <= 10 * n; i++) {
    string num = to_string(i);
    bool isOK = true;
    rep(j, num.size()) {
      int nc = int(num[j]) - 48;
      if (D[nc]) {
        isOK = false;
        break;
      }
    }

    if (isOK) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}