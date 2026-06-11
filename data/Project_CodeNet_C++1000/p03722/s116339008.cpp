#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int MOD = 1000000007;

int main() {
  int N, M; cin >> N >> M;
  ll path[M][3];
  rep(i, M) {
    cin >> path[i][0] >> path[i][1] >> path[i][2];
    path[i][0]--; path[i][1]--;
  } 

  ll s_max[N], s_prev[N];
  ll s_1, s_2;
  rep(i, N) s_max[i] = -1 * pow(2,40); s_max[0] = 0;
  rep(i, M) {
    rep(i, N) s_prev[i] = s_max[i];
    for (auto x: path) s_max[x[1]] = max(s_max[x[1]], s_prev[x[0]]+x[2]); 
  }
  s_1 = s_max[N-1];
  rep(i, M) {
    rep(i, N) s_prev[i] = s_max[i];
    for (auto x: path) s_max[x[1]] = max(s_max[x[1]], s_prev[x[0]]+x[2]); 
  }
  s_2 = s_max[N-1];

  if (s_1>=s_2) cout << s_1 << endl;
  else cout << "inf" << endl;
  return 0;
}