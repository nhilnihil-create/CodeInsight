#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, at, aa, t, a;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> t >> a;
    if(!i)
      at = t, aa = a;
    else {
      ll x = max((at + t - 1) / t, (aa + a - 1) / a);
      at = t * x, aa = a * x;
    }
  }
  cout << at + aa << endl;
}