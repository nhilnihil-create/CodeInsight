#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ll x; cin >> x;
  ll a = x / 11, b = x % 11;
  if (b > 6) cout << a * 2 + 2 << endl;
  else if (b == 0) cout << (a - 1) * 2 + 2 << endl;
  else cout << a * 2 + 1 << endl;
}                                                