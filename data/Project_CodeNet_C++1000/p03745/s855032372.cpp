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
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N) { cin >> A[i]; }
  int ans = 0;
  REP(i, N) {
    int down = i, up = i, tmp = A[i];
    for (int j = i + 1; j <= N; j++) {
      if (j == N ) {
        up = j-1;
        break;
      }
      if (A[j] < tmp) {
        up = j - 1;
        break;
      }
      tmp = A[j];
    }
    tmp = A[i];
    for (int j = i + 1; j <= N; j++) {
      if (j == N) {
        up = j;
        break;
      }
      if (A[j] > tmp) {
        down = j - 1;
        break;
      }
      tmp = A[j];
    }
    ans++;
    i = max(down, up);
  }
  cout << ans << endl;
}