#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1LL << 62;
const double PI = acos(-1);
const double eps = 1e-10;

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(0LL, min(b, d) - max(a, c)) << endl;
  return 0;
}
