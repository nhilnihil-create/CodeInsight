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
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin>>n;
  vector<ll>a(3*n),b(2*n);
  rep(i,3*n)cin>>a[i];
  vector<ll> suml(n+1),sumr(n+1);
  rep(i,n)suml[0]+=a[i];
  rep(i,n)sumr[0]+=a[i+2*n];
  ll res=suml[0]-sumr[0];
  multiset<ll>sel;
  rep(i,n)sel.insert(a[i]);



  repi(i,n,2*n)
  {
    ll ni=i-n+1;
    sel.insert(a[i]);

    auto it=sel.begin();
    suml[ni]=suml[ni-1]+a[i]-*it;
    sel.erase(it);
  }
  reverse(all(a));
  multiset<ll,greater<ll>>ser;

  rep(i,n)ser.insert(a[i]);

  repi(i,n,2*n)
  {
    ll ni=i-n+1;
    ser.insert(a[i]);

    auto it=ser.begin();
    sumr[ni]=sumr[ni-1]+a[i]-*it;
    ser.erase(it);
  }
  rep(i,n+1)
  {
    //cout<<suml[i]<<" "<<sumr[n-i]<<endl;
    chmax(res,suml[i]-sumr[n-i]);
  }
  cout<<res<<endl;




  return 0;

}
