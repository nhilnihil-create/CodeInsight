#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;
  if ((a <= 0) && (b >= 0)) {
    cout << "Zero" << endl;
    return 0;
  }
  if (a > 0) {
    cout << "Positive" << endl;
    return 0;
  }
  if (b < 0) {
    cout << (((b - a) % 2 == 0) ? "Negative" : "Positive") << endl;
    return 0;
  }
}
