#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll q, h, s, d, n;
  cin >> q >> h >> s >> d >> n;
  d = min({8*q, 4*h, 2*s, d});
  s = min({4*q, 2*h, s});
  ll c = d * (n / 2) + s * (n % 2);
  cout << c << endl;
  return 0;
}