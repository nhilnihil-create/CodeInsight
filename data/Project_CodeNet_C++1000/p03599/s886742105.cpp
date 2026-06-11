#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
typedef long double ld;
const int INF = 1e9;
const ll MOD = 1000000007;
int water[10000];
int sugar[10000];
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int main() {
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  water[0] = 1;
  REP(i, F) {
    chmax(water[i + A * 100], water[i]);
    chmax(water[i + B * 100], water[i]);
  }
  sugar[0] = 1;
  REP(i, F) {
    chmax(sugar[i + C], sugar[i]);
    chmax(sugar[i + D], sugar[i]);
  }
  ld _max = -1;
  int W = 0, S = 0;
  water[0] = 0;
  sugar[1] = 0;
  REP(i, F + 1) {
    if (water[i] == 0) continue;
    int j;
    for (j = min(F - i, (i * E) / 100); j >= 0; j--) {
      if (sugar[j] == 1) break;
    }
    ld w = i, s = j;
    ld tmp = 100 * s / (w + s);
    if (_max < tmp) {
      _max = tmp;
      W = i, S = j;
    }
  }
  cout << W + S << " " << S << endl;
}