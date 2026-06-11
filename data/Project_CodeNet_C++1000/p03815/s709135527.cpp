#include <iostream>
using namespace std;
using ll = long long;
int main() {
  ll x;
  cin >> x;
  ll ans = (x / 11) * 2;
  if(x % 11 != 0) {
    ans += (x % 11) > 6 ? 2 : 1;
  }
  cout << ans << endl;
  return 0;
}