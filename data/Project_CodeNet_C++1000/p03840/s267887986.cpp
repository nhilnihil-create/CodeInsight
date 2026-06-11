#include<iostream>
#include <cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  ll a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
  ll ans = (a/2LL)*2LL + b + (d/2LL)*2LL + (e/2LL)*2LL;
  if(a&&d&&e) ans = max(ans, ((a-1)/2)*2LL+b+((d-1)/2)*2LL+((e-1)/2)*2LL+3LL);
  cout << ans << endl;
}
  