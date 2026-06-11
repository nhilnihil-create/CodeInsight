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
int n;
ll a[300005];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  REP(i, 3 * n) cin >> a[i];

  ll suml[300005];
  ll sumr[300005];

  // REP(i, 3 * n) {
  //   l += a[i];
  //   suml[i + 1] = l;
  //   r += a[3 * n - (i + 1)];
  //   sumr[i + 1] = r;
  // }

  priority_queue<ll, vector<ll>, greater<ll>> lque;
  priority_queue<ll> rque;

  ll l = 0, r = 0;
  REP(i, n) {
    l += a[i];
    lque.push(a[i]);
    r += a[3 * n - (i + 1)];
    rque.push(a[3 * n - (i + 1)]);
  }


  suml[0] = l; sumr[0] = r;
  REP(i, n) {
    l += a[n + i];
    lque.push(a[n + i]); l -= lque.top(); lque.pop();
    suml[i + 1] = l;
    r += a[2 * n - (i + 1)];
    rque.push(a[2 * n - (i + 1)]); r -= rque.top(); rque.pop();
    sumr[i + 1] = r;
  }

  ll ans = -LLINF;
  REP(i, n + 1) ans = max(suml[i] - sumr[n - i], ans);
  cout << ans << endl;
}
