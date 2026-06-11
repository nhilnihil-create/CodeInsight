#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n, k;
  cin >> n >> k;
  vector <ll> v(n);
  rep(i, n) cin >> v.at(i);
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  ll res = 0;
  rep(i, k) res += v.at(i);
  cout << res << endl;
}