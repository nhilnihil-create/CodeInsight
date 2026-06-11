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
  bool ok = false;

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      int sum = i * m + j * (n - i);
      sum -= (n - (n - i)) * j;
      if (sum == k) ok = true;
    }
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
} 