#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <bitset>
#include <set>
#include <deque>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;
typedef pair<ll, ll> PLL;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;

// --------------------------------------
int n, m;
vector<vector<ll>> dp;
void warshall_floyd() {
  REP(k, n) {
    REP(i, n) {
      REP(j, n) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
}

struct Edge {
  int x, y, cost;
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  vector<Edge> ve;
  dp.assign(n, vector<ll>(n, INF));
  REP(i, n) dp[i][i] = 0;

  REP(i, n) REP(j, n) dp[i][j] == INF;
  REP(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    dp[a][b] = c;
    dp[b][a] = c;
    ve.push_back(Edge{a, b, c});
  }

  warshall_floyd();
  int count = 0;
  REP(i, m) {
    Edge e = ve[i];
    if(dp[e.x][e.y] != e.cost) count++;
  }
  cout << count << endl;
}
