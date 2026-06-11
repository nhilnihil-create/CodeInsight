#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

ll N, M;
ll A[330][330];

signed main() {
  rep(i,330)
    rep(j, 330)
    A[i][j]=-1;
  cin >> N >> M;
  rep(i,N)
    rep(j,M) {
      cin>>A[i][j];
      A[i][j]--;
    }

  ll ans = N;
  rep(k,M) {
    // 最も参加者の多いスポーツ s を特定する
    vector<ll> n_player(M, 0);
    rep(i,N)
      rep(j,M)
        if (A[i][j] != -1) {
          n_player[A[i][j]]++;
          break;
        }
    //cout << "# of player: ";
    //rep(j,M){
    //  cout<< j << ":" << n_player[j] << " ";
    //}
    //cout << endl;
    ll s = 0;
    rep(j,M)
      if (n_player[j] > n_player[s])
        s = j;

    // スポーツ s の参加者は答えの候補
    // cout << "remove sport " << s << endl;
    ans = min(ans, n_player[s]);

    // スポーツ s を除外する
    rep(i,N)
      rep(j,M)
        if (A[i][j] == s)
          A[i][j]=-1;
  }
  cout << ans << endl;
  return 0;
}
