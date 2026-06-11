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
  int n,p;
  cin >> n >> p;
  ll ans=0;
  ll nxt=0;
  ll cnt=0;
  rep(i,n){
    ll t; cin >> t;
    if(nxt<=t){ 
      ans += (nxt-cnt); 
      nxt=t+p; 
      cnt=t;
    } else {
      nxt=t+p;
    }
  }
  ans+=nxt-cnt;
  
  cout << ans << endl;
  return 0;
}