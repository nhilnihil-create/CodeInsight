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
  ll I,O,T,J,L,S,Z;
  cin >> I >> O >> T >> J >> L >> S >> Z;
  ll ans = 0;
  // O
  ans += O;
  // I,J,L
  vector<ll> a(3);
  a[0] = I; a[1] = J; a[2] = L;
  ll odd = 0;
  REP(i,3) odd += (a[i]%2==1);
  if(odd==3){
    ans += 3;
    REP(i,3) ans += 2*(a[i]/2);
  }else if(odd==1 || odd == 0){
    REP(i,3) ans += 2*(a[i]/2);
  }else{
    bool f = true;
    REP(i,3) if(a[i]==0) f = false;
    if(f) ans += 3;
    REP(i,3) {
      if(a[i]%2==1) ans += 2*(a[i]/2);
      else ans += 2*max(a[i]/2 - 1,0LL);
    }
  }
  cout << ans << endl;
}