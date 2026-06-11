#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll K, S;cin>>K>>S;
  ll ans = 0;

  rep(x, K+1) {
    rep(y, K+1) {
      int z = S-(x+y);
      if (z <= K && z >= 0) {
        if(x+y+z == S) {
          ans ++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}