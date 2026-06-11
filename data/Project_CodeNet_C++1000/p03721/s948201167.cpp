/**
*    author:  yuya1234
*    created: 17.07.2020 17:13:01
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
long double eps = 1.0E-14;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define FORV(i,v) for(auto i=v.begin(); i!=v.end();i++)

#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T>T lcm(T a,T b){return gcd(a,b)*(a/gcd(a,b))*(b/gcd(a,b));}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  //cout<<fixed<<setprecision(15);

  ll n,k;
  cin>>n>>k;

  vector<pair<ll,ll>> p(n);
  ll a,b;
  REP(i,n)
  {
    cin>>a>>b;
    p[i]=make_pair(a,b);
  }

  SORT(p);

  ll ans=0;
  REP(i,n)
  {
    k-=p[i].second;
    if(k-1<0)
    {
      ans=i;
      break;
    }
  }

  cout<<p[ans].first<<endl;

  return 0;
}
