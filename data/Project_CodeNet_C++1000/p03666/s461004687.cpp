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
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pint pair<int,int>
#define pll pair<ll,ll>
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  ll n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  b-=a;
  b=abs(b);
  for(ll i=0;i<=n;i++){
    ll j=n-1-i;
    if(min(i*c-j*d,i*d-j*c)<=b && b<=max(i*c-j*d,i*d-j*c)){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
return 0;}