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
constexpr char ln = '\n';

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n),b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
  }
  ll ans = 0;
  for(int i=n-1; i>=0; i--){
    ans += ((a[i]+ans+b[i]-1)/b[i])*b[i]-(a[i]+ans);
  }
  cout << ans << ln;
  return 0;
}