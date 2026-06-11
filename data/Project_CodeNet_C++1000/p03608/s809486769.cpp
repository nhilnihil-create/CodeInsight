#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;
const ll INF = 1LL<<60;

int MAX_V = 210; // 頂点数
vector<vector<ll>> d(MAX_V, vector<ll>(MAX_V, INF));
void warshall_floyd() {
  for(int k = 0; k < MAX_V; ++k)
    for(int i = 0; i < MAX_V; ++i)
      for(int j = 0; j < MAX_V; ++j)  d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main(){
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> p(r);
  rep(i, r) {
    int a;
    cin >> a;
    --a;
    p[i] = a;
  }
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    d[a][b] = c;
    d[b][a] = c;
  }
  rep(i, n) {
    d[i][i] = 0;
  }
  warshall_floyd();

  ll ans = INF;
  sort(p.begin(), p.end());
  do {
    ll t = 0;
    for (int i = 1; i < r; ++i) {
      t += d[p[i]][p[i - 1]];
    }
    ans = min(ans, t);
  } while (next_permutation(p.begin(), p.end()));
  cout << ans << endl;
}