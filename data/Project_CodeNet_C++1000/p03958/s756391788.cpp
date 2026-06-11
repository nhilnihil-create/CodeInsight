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
  ll num = 0;
  REP(i, T - 1) num += a[i];
  cout << max(a[T - 1] - 1 - num, (ll)0) << endl;
}