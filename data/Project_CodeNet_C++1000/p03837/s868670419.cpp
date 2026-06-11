#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int d[110][110];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  rep(i, n){
    rep(j, n){
      d[i][j] = 1e8;
    }
  }

  rep(i, n){
    d[i][i] = 0;
  }

  vector<int> a(m), b(m), c(m);
  rep(i, m){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
    d[a[i]][b[i]] = c[i];
    d[b[i]][a[i]] = c[i];
  }

  rep(k, n){
    rep(i, n){
      rep(j, n){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  int ans = 0;
  rep(i, m){

    bool ok = true;
    rep(j, n){
      if(d[a[i]][j] + d[j][b[i]] < c[i]){
        ok = false;
      }
    }
    if(!ok){
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
