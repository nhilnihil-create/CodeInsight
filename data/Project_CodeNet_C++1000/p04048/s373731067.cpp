#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>



#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for(ll i = (ll)(n-1); i >= 0; i--)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;

ll rec(ll n,ll x){
  //cout<<n<<" "<<x<<endl;
  ll res=0;
  if(x==0||n==x)return 0;
  if(n>2*x){
    ll nn=(n-x)%x;
    res=rec(nn+x,x)+3*(n-x-nn);
  }
  else if(n<2*x){
    ll nx=x%(n-x);
    res=rec(nx+n-x,nx)+3*(x-nx);
  }
  else {
    res=3*x;
  }
  return res;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,x;cin>>n>>x;

  cout<<rec(n,x)<<endl;
  return 0;

}
