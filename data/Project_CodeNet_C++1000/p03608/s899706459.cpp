#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const int INF = 1001001001;


int MAX_V = 200; // 頂点数
vector<vector<int>> d(MAX_V, vector<int>(MAX_V, INF));
void warshall_floyd() {
  for(int k = 0; k < MAX_V; ++k)
    for(int i = 0; i < MAX_V; ++i)
      for(int j = 0; j < MAX_V; ++j)  d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> t(r);
  rep(i, r) {
    cin >> t[i];
    t[i]--;
  }
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    d[a][b] = c;
    d[b][a] = c;
  }
  rep(i, n) d[i][i] = 0;

  int ans = INF;
  warshall_floyd();
  sort(t.begin(), t.end());
  do {
    int dist = 0;
    rep(i, r - 1) {
      int now = t[i];
      int next = t[i + 1];
      dist += d[now][next];
    }
    chmin(ans, dist);
  } while (next_permutation(t.begin(), t.end()));
  cout << ans << endl;
}