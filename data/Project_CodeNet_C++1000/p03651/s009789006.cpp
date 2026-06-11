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
const ll mod=998244353 ;


int main(){
  int n; ll  k; cin >> n >> k; ll a[n]; ll G;
  rep(i, n){
    cin >> a[i]; if(i==0) G = a[0]; G = gcd(G, a[i]);
  }
  sort(a, a+n);
  if(k<=a[n-1] && k%G==0) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
}
      