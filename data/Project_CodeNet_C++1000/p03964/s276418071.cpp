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
 
const int mx=1000010;
const ll mod=1e9+7;

int main(){  
  int n;
  cin >> n;
  vector<ll> t(n),a(n);
  rep(i,n){ cin >> t[i] >> a[i]; }
  rep(i,n-1){
    if(t[i+1]>=t[i] && a[i+1]>=a[i]){ continue; }
    ll tmpt = (t[i+1]+t[i]-1)/(t[i+1]);
    ll tmpa = (a[i+1]+a[i]-1)/(a[i+1]);
    t[i+1] *= max(tmpt,tmpa);
    a[i+1] *= max(tmpt,tmpa);
  }
  ll ans=t[n-1]+a[n-1];
  cout << ans << endl;
  return 0;
}