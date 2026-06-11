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
#define REP(i,m,n) for(ll i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln = '\n';

const int mx=200010;
const ll mod=1e9+7;

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  vector<ll> v(n);
  rep(i,n){
    cin >> v[i];
  }
  sort(v.rbegin(),v.rend());
  ld ans = 0;
  rep(i,a){
    ans += v[i];
  }
  ans /= (ld)a;
  cout << fixed << setprecision(10) << ans << ln;

  if(v[a-1]!=v[a]){
    cout << 1 << ln; return 0;
  }

  int st=-1,ed=-1;
  rep(i,n){
    if(st==-1 && v[i]==v[a-1]){
      st = i;
    }
    if(st!=-1 && v[i]==v[a-1]){
      ed = i;
    }    
  }

  if(st!=0){
    ll C = ed-st+1;
    ll K = a-st;
    ll ans2 = 1;
    for(ll i=0; i<K; i++){
      ans2 *= (C-i);
      ans2 /= (i+1);
    }
    cout << ans2 << ln;
  } else {
    ll C = ed-st+1;
    ll K = a-st;
    ll ans2 = 0;
    for(ll j=K; j<=min(C,b); j++){
      ll tmp = 1;
      for(ll i=0; i<j; i++){
        tmp *= (C-i);
        tmp /= (i+1);
      }
      ans2 += tmp;
    }
    cout << ans2 << ln;
  }
  return 0;
}