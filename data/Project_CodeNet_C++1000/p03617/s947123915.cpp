#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;

int main() {
  ll q, h, s, d, n; cin >> q >> h >> s >> d >> n;
  ll c = min(q * 4, min(h * 2, s));
  if (c * 2 <= d) cout << n * c << endl;
  else cout << d * (n / 2) + c * (n % 2) << endl;
  
  return 0;
}