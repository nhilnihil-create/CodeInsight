#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

vector<vector<ll>> G;

int main() {
  ll n, ans = 0;
  cin >> n;
  vector<ll> a(n);
  G.assign(n, vector<ll>());
  rep(i, n) {
    cin >> a[i];
    a[i]--;
  }

  rep(i, n) if (a[a[i]] == i) ans++;
  cout << ans / 2 << endl;
  return 0;
}
