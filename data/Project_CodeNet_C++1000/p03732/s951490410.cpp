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
typedef pair<ll, ll> PLL;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;

// --------------------------------------
int n, W;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> W;

  vector<PLL> vw(n);

  REP(i, n) {
    ll v, w;
    cin >> w >> v;
    vw[i] = P(v, w);
  }

  ll d = vw[0].second;
  sort(vw.begin(), vw.end(), greater<PLL>());

  vector<vector<ll>> v_sum(4, vector<ll>());
  vector<vector<ll>> w_sum(4, vector<ll>());

  REP(i, 4) v_sum[i].push_back(0), w_sum[i].push_back(0);
  REP(i, n) {
    PLL p = vw[i];
    int  dd = p.second - d;
    v_sum[dd].push_back(v_sum[dd][v_sum[dd].size() - 1] + p.first);
    w_sum[dd].push_back(w_sum[dd][w_sum[dd].size() - 1] + p.second);
  }

  ll ans = 0;
  REP(i, v_sum[0].size()) REP(j, v_sum[1].size()) REP(k, v_sum[2].size()) REP(l, v_sum[3].size()) {
    ll wa_sum = w_sum[0][i] + w_sum[1][j] + w_sum[2][k] + w_sum[3][l];
    ll va_sum = v_sum[0][i] + v_sum[1][j] + v_sum[2][k] + v_sum[3][l];
    if(wa_sum <= W) ans = max(ans, va_sum);
  }

  cout << ans << endl;
}
