#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

ll mypow(ll a, ll b) {
  ll ans = 1;
  ll tmp;
  ll two;
  while(b>0) {
    two = 1;
    tmp = a;
    while(2*two<b) {
      two *= 2;
      tmp *= tmp;
    }
    b -= two;
    ans *= tmp;
  }
  return ans;
}

int main() {
  ll N, P;
  cin>>N>>P;
  ll even=0, odd=0;
  ll A;
  for(ll i=0;i<N;++i) {
    cin>>A;
    if(A%2==0) even++;
    else odd++;
  }
  ll ans = mypow(2, even);;
  if(odd==0) {
    if(P==1) ans = 0;
  }
  else ans *= mypow(2, odd-1);
  cout<<ans<<endl;
}
