#include<iostream>
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

#define bit(n,k) ((n>>k)&1) //*n no k bit me 1 or 0*/

bool ch(ll k, ll h){
  rep(i,30){
    if(bit(k,i)==0 && bit(h,i)==1){
      return false;
    }
  }
  return true;
}

int main(){
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n),b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
  }

  ll ans = 0;
  vector<ll> op;
  op.emplace_back(k);
  rep(i,30){
    if(bit(k,i)){
      ll msk = 0;
      REP(j,i+1,30){ msk|=(1<<j); }
      ll m2 = 0;
      rep(j,i){ m2|=(1<<j); }
      op.emplace_back((k&msk)|m2);
    }
  }
  for(auto it:op){
    ll tmp = 0;
    rep(j,n)if(ch(it,a[j])){
      tmp += b[j];
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;

  return 0;
}