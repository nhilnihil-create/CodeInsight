#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int countDigit(ll num) {
  int count = 0;

  while (num > 0) {
    num /= 10;
    count++;
  }
  return count;
}

int main(void) {
  ll n;
  cin >> n;

  int ans = countDigit(n);
  ll maxL = (ll)sqrt((double)n);
  maxL++;
  for (ll a = 1LL; a <= maxL; ++a) {
    if (n % a != 0) continue;

    ll b = n / a;
    int cur = max(countDigit(a), countDigit(b));
    if (ans > cur) {
      ans = cur;
    }
  }

  cout << ans << endl;
  
  return 0;
}