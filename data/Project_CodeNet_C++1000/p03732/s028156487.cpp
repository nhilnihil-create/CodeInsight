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

int N;
ll W, w[105], v[105];
vector<ll> x[5];

int main(void) {
  cin >> N >> W;
  rep(i, 0, N) cin >> w[i] >> v[i];
  
  ll w0 = w[0];
  
  rep(i, 0, N) x[w[i]-w0].pb(v[i]);
  
  sort(all(x[0]), greater<ll>());
  sort(all(x[1]), greater<ll>());
  sort(all(x[2]), greater<ll>());
  sort(all(x[3]), greater<ll>());
  
  ll ans = 0;
  for (int A=0; A<=sz(x[0]); A++) for (int B=0; B<=sz(x[1]); B++) for (int C=0; C<=sz(x[2]); C++) for (int D=0; D<=sz(x[3]);  D++) {
    if (A*w0+B*(w0+1)+C*(w0+2)+D*(w0+3)>W) continue;
    ll sum = 0;
    for (int i=0; i<A; i++) sum += x[0][i];
    for (int i=0; i<B; i++) sum += x[1][i];
    for (int i=0; i<C; i++) sum += x[2][i];
    for (int i=0; i<D; i++) sum += x[3][i];
    ans = max(ans, sum);
  }
  
  cout << ans << endl;

    return 0;
}

