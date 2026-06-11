#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int ok = 0;

  for (int i = 0; i <= n; i++) {
    int tmp = k - m * i;
    int mod = (n - 2 * i);
    if (mod == 0) ok = (tmp == 0);
    else {
      if (tmp % mod == 0) if (tmp / mod >= 0 && tmp / mod <= m) ok = 1;
    }
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
} 