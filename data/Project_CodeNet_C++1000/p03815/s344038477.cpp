#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll mod = 1e9 + 7;
 
int main() {
  ll x;
  cin >> x;
  ll rem = x % 11;
  ll ans = (x/11) * 2;
  if (rem != 0){
    if (rem <= 6) ans += 1;
    else ans += 2;
  }
  cout << ans << endl;
  return 0;
}
