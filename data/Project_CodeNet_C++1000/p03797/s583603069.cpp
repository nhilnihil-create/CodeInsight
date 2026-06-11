#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll s, c, ans;
  cin >> s >> c;
  if(2*s >= c) ans = c/2;
  else {
    ans = s;
    c -= 2*s;
    s = 0;
    ans += c/4;
  }
  cout << ans << "\n";
}