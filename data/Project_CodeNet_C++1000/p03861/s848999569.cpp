#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  ll a, b, x;
  cin >> a >> b >> x;
  ll p = a - 1 < 0 ? 0 : (a - 1) / x + 1;
  ll q = b / x + 1;
  cout << q - p << endl;
  return 0;
}