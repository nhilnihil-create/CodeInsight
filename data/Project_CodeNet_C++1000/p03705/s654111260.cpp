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
  ll N, A, B;
  cin >> N >> A >> B;
  ll mn = (N - 1) * A + B;
  ll mx = (N - 1) * B + A;
  if (N == 0) mn = INF;

  cout << max((ll)0, mx - mn + 1) << endl;
}