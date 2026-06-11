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
  int n, x; cin >> n >> x;
  if (x==1 || x==2*n-1) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  vl ans(2*n-1); iota(all(ans),1);
  int rot = (x-n+2*n-1)%(2*n-1);
  rotate(ans.begin(),ans.begin()+rot,ans.end());
  rep(i,2*n-1) {
    cout << ans[i] << endl;
  }
  return 0;
}
