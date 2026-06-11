#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll n, m, a, b;
  cin >> n >> m;
  map<int, int> mp;
  rep(i, m) {
    cin >> a >> b;
    mp[a]++;
    mp[b]++;
  }

  for (auto x : mp) {
    if (x.second % 2 == 1) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
