#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define BIT(X, i) ((X>>i)&1)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define r_all(a) (a).rbegin(), (a).rend()
#define in(x) cin>>x
#define ina(x, n) rep(x_i,n) cin>>x[x_i]
#define outa(x, n) rep(x_i,n) cout<<x[x_i]<<" \n"[x_i==n-1]

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef priority_queue<ll> pq;

const int MOD = 1e9+7;
const int INF = (1<<30);
const ll INFL = (1L<<62);

int main() {
  string s; cin >> s;
  int n = s.length();
  vvl alps(26, vl(n,0));
  for (int i = n-1; i > 0; i--) {
    alps[s[i]-'a'][i]++;
    rep(j,26) {
      alps[j][i-1] += alps[j][i];
    }
  }
  ll ans = 1;
  for (int i = 0; i < n-1; i++) {
    rep(j,26) {
      if (s[i]-'a' == j) continue;
      ans += alps[j][i+1];
    }
  }
  cout << ans << endl;
  return 0;
}
