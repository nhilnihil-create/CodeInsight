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
const ll LINF = 1 << 30;

template<typename T>
void printv(vector<T> const& s) {
  REP(i, SZ(s)) {
    cout << s[i] << " ";
  }
  cout << endl;
}

int main () {
  cin.tie(0);
  cout << setprecision(10);

  int n; cin >> n;
  vll t(n), a(n);
  REP(i, n) cin >> t[i];
  REP(i, n) cin >> a[i];


  if(a[0] != t[n-1]) {
    cout << 0 << endl;
    return 0;
  }

  FOR(i, 1, n-1) {
    if(t[i] != a[i] && t[i-1] != t[i] && a[i] != a[i+1]) {
      cout << 0 << endl;
      return 0;
    }
  }

  FOR(i, 1, n) {
    if(a[i] < t[i] && t[i-1] != t[i]) {
      cout << 0 << endl;
      return 0;
    }
  }

  RREP(i, n-2) {
    if(a[i] > t[i] && a[i] != a[i+1]) {
      cout << 0 << endl;
      return 0;
    }
  }

  if((t[0] != a[0] && a[0] != a[1]) || (a[n-1] != t[n-1] && t[n-1] != t[n-2])) {
    cout << 0 << endl;
    return 0;
  }

  vll v(n, -1);
  v[0] = t[0];
  FOR(i, 1, n) {
    if(t[i] != t[i-1]) v[i] = t[i];
  }
  v[n-1] = a[n-1];
  RREP(i, n-2) {
    if(a[i] != a[i+1]) v[i] = a[i];
  }

  
  ll ans = 1;
  REP(i, n) {
    if(v[i] == -1) {
      ans *= min(t[i], a[i]);
      ans %= MOD;
    }
  }

  cout << ans << endl;

}
