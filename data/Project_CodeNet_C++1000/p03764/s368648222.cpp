#include <iostream>

using namespace std;

#define out(v) cout<<v<<"\n"
#define rep(i,n) for(int i=0;i<(n);++i)

const int MOD = 1e9+7;
using ll = long long;

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N, M; cin >> N >> M;

  ll x[N], y[M];
  rep(i, N)
    cin >> x[i];
  rep(i, M)
    cin >> y[i];

  ll X = 0, Y = 0;
  rep(i, N) {
    X += i * x[i] - (N-1-i)*x[i];
    X %= MOD;
  }
  rep(i, M) {
    Y += i * y[i] - (M-1-i)*y[i];
    Y %= MOD;
  }
  cout << (X * Y) % MOD << "\n";

  return 0;
}
