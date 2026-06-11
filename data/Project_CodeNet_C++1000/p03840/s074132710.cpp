#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll i,o,t,j,l,s,z;
  cin >> i >> o >> t >> j >> l >> s >> z;
  ll ans = 0;
  ans += o * 2;
  int cnt = 0;
  if (i % 2 == 1) cnt++;
  if (j % 2 == 1) cnt++;
  if (l % 2 == 1) cnt++;
  if (j % 2 == i % 2 && i % 2 == l % 2 && l % 2 == j % 2) {
    ans += (i + j + l) * 2;
  } else {
    ans += (i + j + l - 1) * 2;
  }
  if (cnt == 2 && min({j,l,i}) == 0) {
    ans -= 2;
  } 
  cout << ans / 2<< endl;
  return 0;
}
