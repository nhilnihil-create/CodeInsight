#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;

int MAX_V = 100; // 頂点数
vector<vector<int>> d(MAX_V, vector<int>(MAX_V, INF));
void warshall_floyd() {
  for(int k = 0; k < MAX_V; ++k)
    for(int i = 0; i < MAX_V; ++i)
      for(int j = 0; j < MAX_V; ++j)  d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> prev(MAX_V, vector<int>(MAX_V, INF));
  vector<int> a(m), b(m), c(m);
  rep(i, m) {
    cin >> a[i] >> b[i] >> c[i];
    --a[i]; --b[i];
    d[a[i]][b[i]] = c[i];
    d[b[i]][a[i]] = c[i];
  }

  rep(i, n) d[i][i] = 0;

  warshall_floyd();

  int ans = m;
  rep(i, m) {
    bool used = false;
    rep(j, n) {
      if(d[j][a[i]] + c[i] == d[j][b[i]]) used = true;
    }
    if(used) ans--;
  }
  cout << ans << endl;
}