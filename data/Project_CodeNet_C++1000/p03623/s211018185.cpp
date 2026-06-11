#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll x, a, b; cin >> x >> a >> b;
  if (abs(x-a) < abs(x-b)) cout << 'A' << endl;
  else cout << 'B' << endl;
}