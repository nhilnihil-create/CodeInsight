//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()



int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll ans = a*b*((c-c/2*2));
  ans = min(ans, b*c*(a-a/2*2));
  ans = min(ans, c*a*(b-b/2*2));
  cout << ans << endl;
  return 0;
}