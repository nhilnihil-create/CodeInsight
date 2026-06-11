#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

using namespace std;

typedef long long ll;
typedef long double ld;

using P = pair<int, int>;

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

int main(void) {
  int n;
  cin >> n;
  ll T = 1, A = 1;
  rep(i, 0, n) {
    ll t, a;
    cin >> t >> a;
    ll x = (T+t-1)/t, y = (A+a-1)/a;
    ll r = max(x, y);
    T = r*t;
    A = r*a;
  }
  
  ll ans = A+T;
  
  cout << ans << endl;

    return 0;
}

