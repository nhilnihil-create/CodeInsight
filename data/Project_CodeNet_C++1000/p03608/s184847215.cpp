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
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};
int dx9[9]={0,1,0,-1,1,-1,1,0,-1};
int dy9[9]={0,1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;
typedef pair<ll, ll> PLL;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;

// --------------------------------------
int n, m, R;
int r[10];
ll d[205][205];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> m >> R;
  REP(i, n) REP(j, n) d[i][j] = INF;
  REP(i, R) cin >> r[i], r[i]--;

  REP(i, m) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;b--;
    if(d[a][b] > c) d[a][b] = d[b][a] = c;
  }
  sort(r, r + R);
  REP(k, n) REP(i, n) REP(j, n) {
    if(d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
  }

  ll ans = INF;

  do {
    ll sum = 0;
    FOR(i, 1, R) sum += d[r[i - 1]][r[i]];
    ans = min(ans, sum);
  } while(next_permutation(r, r + R));
  cout << ans << endl;
}
