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
  int N, M;
  cin >> N >> M;
  vector<int> a(N), b(N);
  REP(i, N) cin >> a[i] >> b[i];
  vector<int> c(M), d(M);
  REP(i, M) cin >> c[i] >> d[i];
  REP(i, N) {
    ll dis = 1e16;
    int coor = -1;
    REP(j, M) {
      ll disnow = abs(a[i] - c[j]) + abs(b[i] - d[j]);
      if (disnow < dis) {
        coor = j;
        dis = disnow;
      }
    }
    cout << coor + 1 << endl;
  }
}