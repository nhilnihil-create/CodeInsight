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
int main() {
  int K, T;
  cin >> K >> T;
  vector<ll> a(T);
  REP(i, T) cin >> a[i];
  sort(a.begin(), a.end());
  ll mn = 1e15;
  vector<ll> ruiseki(T);
  ruiseki[0] = a[0];
  for (int i = 1; i < T; i++) {
    ruiseki[i] = ruiseki[i - 1] + a[i];
  }
  REP(i, T) {
    ll b = ruiseki[i], c = ruiseki[T - 1] - ruiseki[i];
    mn = min(mn, abs(b - c));
  }
  cout << max((ll)0, mn - 1) << endl;
}