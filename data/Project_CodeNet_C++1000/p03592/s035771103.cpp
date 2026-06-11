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
struct ocello {
  int white;
  int black;
};
int main() {
  int N, M, K;
  cin >> N >> M >> K;
  REP(i, N+1) {
    REP(j, M+1) {
      ll cnt = i * M + j * N - 2*i * j;
      if (cnt == K) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}