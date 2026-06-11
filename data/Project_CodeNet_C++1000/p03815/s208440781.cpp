#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ll x;
  cin >> x;
  
  ll ans = (x/11) * 2;
  if (x % 11 == 0) {
  } else if (x % 11 <= 6) {
    ans += 1;
  } else {
    ans += 2;
  }
  
  cout << ans << endl;
}