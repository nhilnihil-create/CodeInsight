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
  ll n,a,b;
  cin >> n >> a >> b;
  vector<ll> v(n);
  rep(i,n){ cin >> v[i]; }
  sort(v.rbegin(),v.rend());

  ld ans=0;
  rep(i,a){ ans+=v[i]; }
  ans/=a;
  cout << fixed << setprecision(10) << ans << endl;
  
  int cntin=0,cntout=0;
  rep(i,n){
    if(v[i]==v[a-1]){
      if(i<a){cntin++;}else{cntout++;}
    }
  }
  ll ansc=1;
  if(cntin!=a){
    rep(i,cntin){ ansc=ansc*(cntin+cntout-i)/(i+1); }
  }else{
    ll tmp=1;
    n=cntin+cntout;
    rep(i,a){ tmp=tmp*(n-i)/(i+1); }
    ansc=tmp;
    for(int i=a+1; i<=min(b,n); i++){
      tmp = tmp*(n-i+1)/i;
      ansc+=tmp;
    }
  }
  cout << ansc << endl;
  return 0;
}