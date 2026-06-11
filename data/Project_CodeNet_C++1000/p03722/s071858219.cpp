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

struct edge{ll to,from,cost;};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m;cin>>n>>m;
  vector<edge>ed(m);
  rep(i,m)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    ed[i]={b,a,-c};

  }
  vector<ll>dist(n,1e18);
  dist[0]=0;
  rep(i,n){
    rep(j,m){
      auto te=ed[j];
      chmin(dist[te.to],dist[te.from]+te.cost);
    }
  }
  ll f=dist[n-1];
  rep(i,n){
    rep(j,m){
      auto te=ed[j];
      chmin(dist[te.to],dist[te.from]+te.cost);
    }
  }
  if(f>dist[n-1])cout<<"inf"<<endl;
  else cout<<-dist[n-1]<<endl;


  return 0;

}
