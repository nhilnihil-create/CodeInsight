#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
ll gcd(ll a, ll b) {
  if (a % b == 0) {
    return (b);
  } else {
    return (gcd(b, a % b));
  }
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int main() {
  int N;
  cin >> N;
  ll ans = 1;
  REP(i, N) {
    ll T;
    cin >> T;
    ans = lcm(T, ans);
  }
  cout << ans << endl;
}