#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
const ll mod = 1000000007;

int main()
{
  int n; cin >> n;
  string s1, s2; cin >> s1 >> s2;

  ll ans = 1;
  int b = 0;
  for (int i=0; i<n; i++) {
    if (s1[i] == s2[i]) {
      if (b == 0) ans *= 3;
      else if (b == 1) ans *= 2;

      b = 1;
    } else {
      if (b == 0) ans *= 6;
      else if (b == 1) ans *= 2;
      else ans *= 3;

      i++;
      b = 2;
    }
    ans %= mod;
  }
  cout << ans << endl;

  return 0;
}
