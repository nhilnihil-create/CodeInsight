#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll a, b, x;
  cin >> a >> b >> x;
  ll ans = b/x;
  if(a%x==0) ans -= a/x-1;
  else ans -= a/x;
  cout << ans << endl;
  return 0;
}