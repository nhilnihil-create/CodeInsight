#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define _GLIBCXX_DEBUG
const int MOD = 1000000007;

int main() {
  ll x;
  cin >> x;
  ll ans = x/11*2;
  if (x%11!=0) {
    if (x%11<7) ans++;
    else ans += 2LL;
  }
  cout << ans << endl;
}
