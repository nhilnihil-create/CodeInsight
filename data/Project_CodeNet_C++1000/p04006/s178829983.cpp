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
  int N; ll X; cin >> N >> X; ll a[2*N];
  rep(i, N) cin >> a[i];
  for(int i=N; i<2*N; i++){
    a[i] = a[i-N];
  }
  ll ans = longinf; ll mi[N];
  rep(i, N) mi[i] = a[i];
  rep(i, N){
    ll tmp = 0;
    rep(j, N){
      mi[j] = min(mi[j], a[j+N-i]);
    }
    rep(j, N){
      tmp+=mi[j];
    }
    tmp+=i*X;
    ans=min(ans, tmp);
  }
  cout << ans << endl;
}