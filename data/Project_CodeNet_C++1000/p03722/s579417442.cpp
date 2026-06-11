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
int n, m;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  vector<int> a(m + 1);
  vector<int> b(m + 1);
  vector<ll> c(m + 1);

  REP(i, m) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--; c[i] = -c[i];
  }

  vector<ll> dist(n + 1, LLINF);
  dist[0] = 0;

  REP(i, n - 1) {
    REP(j, m) {
      if(dist[a[j]] == LLINF) continue;
      if(dist[b[j]] > dist[a[j]] + c[j]) {
        dist[b[j]] = dist[a[j]] + c[j];
      }
    }
  }

  ll ans = dist[n - 1];

  vector<bool> negative(n + 1, false);

  REP(i, n) {
    REP(j, m) {
      if(dist[a[j]] == LLINF) continue;

      if (dist[b[j]] > dist[a[j]] + c[j]) {
        dist[b[j]] = dist[a[j]] + c[j];
        negative[b[j]] = true;
      }

      if (negative[a[j]] == true) {
        negative[b[j]] = true;
      }
    }
  }

  if(negative[n - 1]) cout << "inf" << endl;
  else cout << -ans << endl;
}
