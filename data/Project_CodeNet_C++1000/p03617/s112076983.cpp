#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;

int main() {
  ll q, h, s, d;
  cin >> q >> h >> s >> d;
  ll n;
  cin >> n;
  ll x = min({q * 8, h * 4, s * 2, d});
  ll y = min({q * 4, h * 2, s});
  cout << n / 2 * x + (n % 2) * y << endl;
  return 0;
} 