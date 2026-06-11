#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int k, s;
  cin >> k >> s;
  ll cnt = 0;
  rep(x,k+1) {
    rep(y,k+1) {
      int z = s-x-y;
      if (z>=0 && z<=k) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
