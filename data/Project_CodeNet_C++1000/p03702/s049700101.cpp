#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define RREP(i, n) RFOR(i, n, 0)
#define MFOR(i, m) for(auto i=(m).begin();i!=(m).end();i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())

typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll << 60;

template<typename T>
void printv(vector<T> const& s) {
  REP(i, SZ(s)) {
    cout << s[i] << " ";
  }
  cout << endl;
}

ll n, a, b;
vll h;

bool ok(ll k) {
  ll cnt = 0;
  // cout << "k:" << k << endl;
  REP(i, n) {
    if(h[i] > b * k) cnt += (h[i] - b * k + (a-b) - 1) / (a-b);
  }
  return cnt <= k;
}

int main () {
  cin.tie(0);
  cout << setprecision(10);

  cin >> n >> a >> b;
  h.resize(n);
  REP(i, n) {
    cin >> h[i];
  }
  if(n == 1) {
    cout << (h[0] + a - 1) / a << endl;
    return 0;
  }

  ll l = -1, r = 1e9+1;
  while(l != r) {
    ll mid = (l + r) / 2;
    if(ok(mid)) r = mid;
    else l = mid+1;
  }

  cout << l << endl;
}
