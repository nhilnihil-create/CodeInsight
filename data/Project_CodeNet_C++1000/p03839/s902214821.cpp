#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
const int mx=200010;
const ll mod=1e9+7;

int main(){
  int n,m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  vector<ll> r(n+1,0);
  vector<ll> p(n+1,0);
  rep(i,n){
    r[i+1] = r[i]+a[i];
    p[i+1] = p[i]+(a[i]>0?a[i]:0);
  }

  ll ans = 0;
  rep(i,n-m+1){
    ll tmp = p[i]+p[n]-p[i+m] + (r[i+m]-r[i]>0? r[i+m]-r[i]:0);
    ans = max(tmp,ans);
  }
  cout << ans << endl;
  return 0;
}