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
ll H, W;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> H >> W;

  ll ans = LLINF;
  ll size[3];

  if(H % 3 == 0 || W % 3 == 0) ans = 0;
  if(H >= 3) ans = min(ans, H);
  if(W >= 3) ans = min(ans, W);

  FOR(i, 1, H) {
    ll h = H - i;

    size[0] = W * i;
    size[1] = (W / 2) * h;
    size[2] = h * W - size[1];
    sort(size, size + 3);
    ans = min(ans, size[2] - size[0]);
  }

  FOR(i, 1, W) {
    ll w = W - i;

    size[0] = H * i;
    size[1] = (H / 2) * w;
    size[2] = H * w - size[1];
    sort(size, size + 3);
    ans = min(ans, size[2] - size[0]);
  }

  cout << ans << endl;
}
