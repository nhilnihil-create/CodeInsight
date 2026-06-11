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

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;

using vec=vector<ll>;
using mat=vector<vec>;

vec mul(vec &a,vec &b)
{
  vec res(a.size());
  rep(i,a.size())
  {
    res[i]=b[a[i]];
  }

  return res;
}

vec pow(vec &a,ll n)
{
  vec b(a.size());
  for(ll i=0;i<a.size();i++)
  {
    b[i]=i;
  }
  while(n>0)
  {
    if(n&1)b=mul(a,b);
    a=mul(a,a);
    n>>=1;
  }
  return b;
}
int  main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin>>n;
  vec x(n);
  vec dx(n-1);
  rep(i,n)cin>>x[i];
  rep(i,n-1)
  {
    dx[i]=x[i+1]-x[i];
  }


  ll m,k;
  cin>>m>>k;
  vector<ll> nx(n-1);
  rep(i,n-1)nx[i]=i;
  rep(i,m)
  {
    ll a;cin>>a;
    a--;
    swap(nx[a-1],nx[a]);
  }
  vec t=pow(nx,k),dans=mul(t,dx);
  cout<<x[0]<<endl;
  ll cnt=x[0];
  rep(i,n-1)
  {
    cnt+=dans[i];
    cout<<cnt<<"\n";
  }
  cout<<flush;


  return 0;

}
