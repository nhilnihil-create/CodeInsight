#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll w, a, b;
  cin >> w >> a >> b;
  if (a > b) swap(a, b);
  cout << max(0LL, b - (a + w)) << endl;
  return 0;
}
