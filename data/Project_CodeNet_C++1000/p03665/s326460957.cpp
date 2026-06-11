//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()


int main() {
  ll n, p;
  cin >> n >> p;
  bool odd = 0;
  rep(i, n) {
    int a;
    cin >> a;
    if (a%2 != 0) odd = true;
  }
  if (odd) {
    ll m = pow(2, n-1);
    cout << m << endl;
    return 0;
  }
  if (p == 0) {
    ll m = pow(2, n);
    cout << m << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}