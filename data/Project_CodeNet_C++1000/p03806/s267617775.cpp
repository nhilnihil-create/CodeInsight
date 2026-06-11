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

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;

// --------------------------------------
int n, ma, mb;
int a[45], b[45], c[45];
int dp[45][405][405];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> ma >> mb;
  REP(i, n) {
    cin >> a[i + 1] >> b[i + 1] >> c[i + 1];
  }
  REP(i, n + 1) {
    REP(j, 401) {
      REP(k, 401) {
        dp[i][j][k] = INF;
      }
    }
  }
  REP(i, n + 1) {
    dp[i][0][0] = 0;
  }
  FOR(i, 1, n + 1) {
    FOR(j, 0, 401) {
      FOR(k, 0, 401) {
        if(j - a[i] >= 0 && k - b[i] >= 0) {
          dp[i][j][k] = min(dp[i - 1][j - a[i]][k - b[i]] + c[i], dp[i - 1][j][k]);
        } else {
          dp[i][j][k] = dp[i - 1][j][k];
        }
      }
    }
  }

  int ans = INF;
  int i = ma, j = mb;
  while(i <= 400 && j <= 400) {
    ans = min(ans, dp[n][i][j]);
    i += ma;
    j += mb;
  }

  cout << (ans == INF ? -1 : ans) << endl;
}
