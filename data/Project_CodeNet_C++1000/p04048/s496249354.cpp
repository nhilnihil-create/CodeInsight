#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main(){
  ll N, X; cin >> N >> X;
  ll ans = N;
  ll h = X, w = N-X;
  while(1){
    if(w%h==0){
      ans += h*(2*w/h-1);
      break;
    }
    ans += w/h*h*2;
    ll ww = w, hh = h;
    w = hh;
    h = ww - ww/hh*hh;
  }
  cout << ans << endl;
}