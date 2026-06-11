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
#define rep(i,N) for(int (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const double PI = 3.1415926535897932384626433832795;
const int mod = 1000000007;
const int INF = 1001001001;


int MAX_V = 100; // 頂点数
vector<vector<int>> d(MAX_V, vector<int>(MAX_V, INF));
void warshall_floyd() {
  for (int i = 0; i < MAX_V; ++i) d[i][i] = 0;
  for (int k = 0; k < MAX_V; ++k)
    for (int i = 0; i < MAX_V; ++i)
      for (int j = 0; j < MAX_V; ++j)  d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m), c(m);
  rep(i, m) {
    int s, t, u;
    cin >> s >> t >> u;
    s--; t--;
    a[i] = s;
    b[i] = t;
    c[i] = u;
    d[a[i]][b[i]] = c[i];
    d[b[i]][a[i]] = c[i];
  }

  warshall_floyd();

  int ans = 0;
  rep(i, m) {
    int na = a[i], nb = b[i], nc = c[i];
    bool used = false;
    rep(j, n) {
      if (d[na][j] + nc == d[nb][j]) used = true;
    }
    if(!used) ans++;
  }

  cout << ans << endl;

}