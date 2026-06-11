#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n;
  cin >> n;
  ll m = 0, tmp;
  rep(i, n) {
    ll a, b; cin >> a >> b;
    if (a > m) {
      m = a; tmp = b;
    }
  }
  cout << m + tmp << endl;
}