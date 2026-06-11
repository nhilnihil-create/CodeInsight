#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)

template<class T>using vv = vector<vector<T>>;
constexpr ll INF = 1e15;
int main() {
  int N, M;
  cin >> N >> M;

  vv<ll> cost(N, vector<ll>(N, INF));
  vi A(M), B(M), C(M);
  rep(i, M) {
    cin >> A[i] >> B[i] >> C[i];
    --A[i], --B[i];
    cost[A[i]][B[i]] = cost[B[i]][A[i]] = C[i];
  }
  rep(i, N)
    cost[i][i] = 0;

  rep(k, N) rep(i, N) rep(j, N)
    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

  int ans = 0;
  rep(i, M) {
    bool ok = false;
    rep(from, N) {
      rep(to, N) {
        if (cost[from][to] == cost[from][A[i]] + C[i] + cost[B[i]][to]) {
          ok = true;
          break;
        }
      }
      if (ok)
        break;
    }
    if (!ok)
      ++ans;
  }
  cout << ans << endl;

  return 0;
}
