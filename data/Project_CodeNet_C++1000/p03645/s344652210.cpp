/**
*    author:  yuya1234
*    created: 13.07.2020 14:29:39
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

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
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  //std::cout << std::fixed << std::setprecision(15);

  int n,m;
  cin>>n>>m;

  int a[m],b[m],ca[200010];
  MEMSET(ca,0);

  vector<int> v;
  
  REP(i,m)
  {
    cin>>a[i]>>b[i];
    if(a[i]==1)v.emplace_back(b[i]);
    if(b[i]==n)ca[a[i]]=1;
  }

  string ans="IMPOSSIBLE";

  REP(i,SZ(v)){
    if(ca[v[i]]==1)ans="POSSIBLE";
  }

  cout<<ans<<endl;

  return 0;
}