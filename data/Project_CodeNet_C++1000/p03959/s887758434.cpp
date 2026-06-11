#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define BIT(X,i) ((X>>i)&1)
#define REP(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define r_all(a) (a).rbegin(), (a).rend()
#define ina(x,n) rep(x_i,n) cin>>x[x_i]
#define outa(x,n) rep(x_i,n) cerr<<x[x_i]<<" \n"[x_i==n-1]

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef priority_queue<ll> pq;

const int MOD = 1e9+7;
const int INF = (1<<28);
const ll INFL = (1LL<<61);

int main() {
  ll n, ans = 1;
  cin >> n;
  vl t(n), a(n); ina(t,n); ina(a,n);
  vl mns(n,1), mxs(n,INFL);
  mns[0] = mxs[0] = t[0];
  REP(i,1,n) {
    if (t[i] != t[i-1]) {
      mxs[i] = mns[i] = t[i];
    } else {
      mxs[i] = t[i];
    }
  }
  
  if (a[n-1] < mns[n-1] || a[n-1] > mxs[n-1]) {
    cout << 0 << endl;
    return 0;
  }

  mns[n-1] = mxs[n-1] = a[n-1];
  for (int i = n-2; i >= 0; i--) {
    if (a[i] != a[i+1]) {
      if (mns[i] <= a[i] && a[i] <= mxs[i]) {
          mns[i] = mxs[i] = a[i];
      } else {
        ans = 0;
      }
    } else {
      mxs[i] = min(mxs[i], a[i]);
    }
  }
  outa(mxs, n);
  outa(mns, n);
  rep(i,n) {
    ans *= (mxs[i] - mns[i] + 1);
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
