#include<iostream>
#include<string>
#include<cstring>
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
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
#define PI 3.141592653589793

ll ans = 0;

void gcd(ll a, ll b){
  if(a<b) swap(a, b);
  //cout << a << " " << b << endl;
  if(a%b){
    ans+=(a/b)*2*b;
    //cout << ans << endl;
    gcd(a%b, b);
  }
  else{
    ans+=(a/b)*2*b; ans-=b; return;
  }
}


int main(){
  ll n, x; cin >> n >> x;
  ll b = n-x;
  ans+=n;
  gcd(x, b);
  cout << ans << endl;
}