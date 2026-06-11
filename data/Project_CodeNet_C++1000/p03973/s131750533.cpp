#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int main() {
  int n;
  cin >> n;
  vector<ll> la(n);
  for (ll &a: la) cin >> a;
  ll ans = 0;
  ll money = 0;
  for (ll a: la) {
    // cerr << a << " " << money << endl;
    if (a-1 <= money) {
      money = max(money, a);
      continue;
    }
    ans += (a-1)/(money+1);
    if (money == 0) money = 1;
  }
  cout << ans << endl;
}

