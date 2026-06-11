#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll w, a, b;
  cin >> w >> a >> b;
  if (a > b) {
    ll tmp = a;
    a = b;
    b = tmp;
  }
  if (b <= a+w) cout << 0 << endl;
  else cout << abs(a+w-b) << endl;
}