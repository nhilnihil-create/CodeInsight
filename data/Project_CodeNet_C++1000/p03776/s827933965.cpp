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
int n, a, b;
ll comb[51][51];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> a >> b;
  vector<ll> v(n);
  REP(i, n) cin >> v[i];

  comb[0][0] = 1;
  FOR(i, 1, 51) REP(j, i + 1) {
    comb[i][j] += comb[i - 1][j];
    if(j > 0) comb[i][j] += comb[i - 1][j - 1];
  }

  sort(v.begin(), v.end(), greater<ll>());

  ll sum = 0;
  REP(i, a) sum += v[i];
  cout << fixed << setprecision(8) << (double)sum / a << endl;

  int p;
  REP(i, n) if(v[a - 1] == v[i]) p++;
  if(v[a - 1] == v[0]) {
    ll ans = 0;
    FOR(i, a, min(b, p) + 1) {
      ans += comb[p][i];
    }
    cout << ans << endl;
  } else {
    int ap = 0;
    REP(j, a) if(v[a - 1] == v[j]) ap++;
    cout << comb[p][ap] << endl;
  }
}
