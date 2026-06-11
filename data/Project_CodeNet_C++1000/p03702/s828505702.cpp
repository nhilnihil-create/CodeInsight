#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef unordered_map<ll, ll> U_MAP;
typedef priority_queue<ll> pq;
typedef priority_queue<ll, vector<ll>, greater<ll>> rpq;
const int INF = 1e9, MOD = 1e9 + 7, ohara = 1e6 + 10;
const ll LINF = 1e18;

#define rep(i, n) for (ll(i) = 0; (i) < (int)(n); (i)++)
#define rrep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrrep(i, a, b) for (ll i = (a); i >= (b); i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout << (x) << endl
#define doublecout(a) cout << fixed << setprecision(15) << a << endl;
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back

//------ Believe yourself as a genius!!!!!! ------

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
// int dy[]={-1,0,1,-1,1,-1,0,1};int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"), s;
ll n, cnt, ans, a, b, c, d, tmp, m, h[ohara], w, x, y, sum, k, q;

bool check(ll kai) {
  ll now[n + 10] = {}, ret = 0;
  rep(i, n) now[i] = h[i];
  rep(i, n) {
    ld hika1, hika2;
    hika1 = (ld)now[i] / (ld)b;
    hika2 = (ld)kai;
    if (hika1 < hika2) {
      now[i] = 0;
    } else {
      now[i] -= b * kai;
    }
  }
  ll hera = a - b;
  rep(i, n) {
    if (now[i] <= 0) continue;
    ll cost = (now[i] % hera == 0 ? now[i] / hera : now[i] / hera + 1);
    ret += cost;
  }
  if (ret <= kai)
    return true;
  else
    return false;
}

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> a >> b;
  rep(i, n) cin >> h[i];
  ll le = 0, ri = LINF, mid;
  while (ri - le > 1) {
    mid = (le + ri) / 2;
    if (check(mid))
      ri = mid;
    else
      le = mid;
  }
  rrep(i, max(0LL, le - 3), min(ri + 4, LINF)) {
    if (check(i)) {
      Cout(i);
      return 0;
    }
  }
  return 0;
}
