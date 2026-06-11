#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define each(i,a) for (auto&& i : a)
#define FOR(i,a,b) for (ll i=(a),__last_##i=(b);i<__last_##i;i++)
#define RFOR(i,a,b) for (ll i=(b)-1,__last_##i=(a);i>=__last_##i;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define __GET_MACRO3(_1, _2, _3, NAME, ...) NAME
#define rep(...) __GET_MACRO3(__VA_ARGS__, FOR, REP)(__VA_ARGS__)
#define rrep(...) __GET_MACRO3(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(),(a).end()
#define chmin(x,v) x = min(x, v)
#define chmax(x,v) x = max(x, v)

const ll linf = 1e18;
const double eps = 1e-12;
const double pi = acos(-1);

template<typename T>
istream& operator>>(istream& is, vector<T>& vec) {
  each(x,vec) is >> x;
  return is;
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
  rep(i,vec.size()) {
    if (i) os << " ";
    os << vec[i];
  }
  return os;
}
template<typename T>
ostream& operator<<(ostream& os, const vector< vector<T> >& vec) {
  rep(i,vec.size()) {
    if (i) os << endl;
    os << vec[i];
  }
  return os;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, m; cin >> n >> m;
  vector<ll> a(n); cin >> a;
  vector<ll> start(2*m), end(2*m), endlen(2*m);
  ll sum = 0;
  rep(i, n-1) {
    ll l = a[i]-1, r = a[i+1]-1;
    if (r < l) r += m;
    sum += r - l;
    ++l;
    start[l]++;
    if (m+l < 2*m) start[m+l]++;
    end[r]++;
    endlen[r] += r-l;
    if (m+r < 2*m) {
      end[m+r]++;
      endlen[m+r] += r-l;
    }
  }
  ll ans = 0, now = 0, cnt = 0;
  rep(i, 2*m) {
    now += cnt;
    cnt += start[i];
    cnt -= end[i];
    chmax(ans, now);
    // cout << i << " " << now << endl;
    now -= endlen[i];
  }
  ans = sum - ans;
  cout << ans << endl;
}
