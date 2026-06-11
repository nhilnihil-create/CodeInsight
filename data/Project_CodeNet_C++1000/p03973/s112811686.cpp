//#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define IN(a, b, x) (a<=x&&x<b)
#define MP make_pair
#define PB push_back
#ifdef int
const ll INF = (1LL<<60);
#else
const int INF = (1LL<<30);
#endif
const double PI = 3.14159265359;
const double EPS = 1e-12;
const int MOD = 1000000007;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int a[100010], b[100010];
signed main(void)
{
  int n;
  cin >> n;
  REP(i, n) cin >> a[i];

  int idx = 1, ret = 0;
  REP(i, n) {
    if(a[i] == idx) idx++;
    else {
      ret += (a[i]-1)/idx;
      if(i == 0) idx++;
    }
  }
  cout << ret << endl;

  return 0;
}
