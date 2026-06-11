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

  ll n; cin >> n;
  vll a(n+1);
  ll s = 0;
  REP(i, n) {
    cin >> a[i];
    s += a[i];
  }
  a[n] = a[0];
  vll b(n);
  REP(i, n) {
    b[i] = a[i+1] - a[i];
  }

  // printv(b);


  ll su = n * (n + 1) / 2ll;
  // cout << s << ":" << su << endl;
  if(s % su == 0) {
    ll cnt = 0;
    REP(i, n) {
      b[i] -= s / su;
      if(abs(b[i]) % n != 0) {
        cout << "NO" << endl;
        return 0;
      }
      cnt += abs(b[i]) / n;
    }
    if(cnt == s / su) cout << "YES" << endl;
    else cout << "NO" << endl;
  } else {
    cout << "NO" << endl;
  }
}
