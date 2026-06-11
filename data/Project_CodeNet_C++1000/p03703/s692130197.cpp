#pragma target("avx")
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
ll n, cnt, ans, a[ohara], b, c, d, tmp, m, h, w, x, y, k, q;
ll hozi[ohara], dat[ohara], bit[ohara];
U_MAP mp;
P p[ohara];

struct LazySegmentTree {
 private:
  int n;
  vector<ll> node, lazy;

 public:
  LazySegmentTree(vector<ll> v) {
    int sz = (int)v.size();
    n = 1;
    while (n < sz) n *= 2;
    node.resize(2 * n - 1);
    lazy.resize(2 * n - 1, 0);

    for (int i = 0; i < sz; i++) node[i + n - 1] = v[i];
    for (int i = n - 2; i >= 0; i--)
      node[i] = node[i * 2 + 1] + node[i * 2 + 2];
  }

  void eval(int k, int l, int r) {
    if (lazy[k] != 0) {
      node[k] += lazy[k];
      if (r - l > 1) {
        lazy[2 * k + 1] += lazy[k] / 2;
        lazy[2 * k + 2] += lazy[k] / 2;
      }
      lazy[k] = 0;
    }
  }

  void add(int a, int b, ll x, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    eval(k, l, r);
    if (b <= l || r <= a) return;
    if (a <= l && r <= b) {
      lazy[k] += (r - l) * x;
      eval(k, l, r);
    } else {
      add(a, b, x, 2 * k + 1, l, (l + r) / 2);
      add(a, b, x, 2 * k + 2, (l + r) / 2, r);
      node[k] = node[2 * k + 1] + node[2 * k + 2];
    }
  }

  ll getsum(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    eval(k, l, r);
    if (b <= l || r <= a) return 0;
    if (a <= l && r <= b) return node[k];
    ll vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
    ll vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
    return vl + vr;
  }
};

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  rep(i, n) cin >> a[i];

  rep(i, n) a[i] -= k;
  rrep(i, 1, n) a[i] += a[i - 1];
  rep(i, n) hozi[i] = a[i], p[i] = m_p(a[i], i);
  LazySegmentTree seg(vector<ll>(ohara, 0));

  ll lim = 0;
  sort(a, a + n);
  sort(p, p + n);
  rep(i, n) { dat[p[i].se] = i; }
  rep(i, n) {
    ll le = 0, ri = n - 1, mid;
    while (ri - le > 1) {
      mid = (le + ri) / 2;
      if (a[mid] >= lim)
        ri = mid;
      else
        le = mid;
    }
    tmp = n - 1;
    rrep(j, max(le - 3, 0LL), min(ri + 4, n)) {
      if (a[j] >= lim) {
        tmp = j;
        break;
      }
    }
    // cout << a[ri] << " " << lim << "\n";
    if (a[tmp] >= lim) ans += n - tmp - seg.getsum(tmp, ohara - 1);
    lim = hozi[i];
    seg.add(dat[i], dat[i] + 1, 1);
    // Cout(ans);
  }

  // rep(i, n) cout << hozi[i] << " ";
  Cout(ans);
  return 0;
}
