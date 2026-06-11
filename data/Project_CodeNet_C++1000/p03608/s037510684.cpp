#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,M,R; cin >> N >> M >> R;
  ll G[N][N];

  vector<int> RL(R);
  rep(i, R) {
    cin >> RL[i];
    RL[i]--;
  }
  sort(RL.begin(), RL.end());

  rep(i, N) rep(j, N) G[i][j] = INF;
  rep(i, M) {
    ll a,b,c; cin >> a >> b >> c;
    a--;
    b--;
    G[a][b] = min(G[a][b], c);
    G[b][a] = min(G[b][a], c);
  }

  rep(k, N) {
    rep(i, N) {
      rep(j, N) {
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
      }
    }
  }

  ll ans = INF;
  do {
    ll tmp = 0;
    for(int i = 1; i < R; i++) {
      tmp += G[RL[i - 1]][RL[i]];
    }
    ans = min(ans, tmp);
  } while (next_permutation(RL.begin(), RL.end()));

  cout << ans << endl;
}
