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

const int mx=100010;
const ll mod=1e9+7;


int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  ll ans=0;
  vector<ll> x(n);
  rep(i,n){
    cin >> x[i];
  }
  rep(i,n-1){
    ans += min((x[i+1]-x[i])*a,b);
  }
  cout << ans << endl;
  return 0;
}