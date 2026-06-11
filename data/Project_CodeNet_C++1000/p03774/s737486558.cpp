/**
*    author:  yuya1234
*    created: 08.07.2020 14:13:33
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define FORV(i,v) for(auto i=v.begin(); i!=v.end();i++)

#define ALL(v) (s).begin(), (s).end()
#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int n,m;
  cin>>n>>m;

  ll a[50][2],c[50][2];
  REP(i,n)cin>>a[i][0]>>a[i][1];
  REP(i,m)cin>>c[i][0]>>c[i][1];

  ll amin,ans;
  REP(i,n)
  {
    amin=INT_MAX;
    ans=0;
    REP(j,m)
    {
      if(amin>abs(a[i][0]-c[j][0])+abs(a[i][1]-c[j][1]))
      {
        amin=abs(a[i][0]-c[j][0])+abs(a[i][1]-c[j][1]);
        ans=j+1;
      }
    }
    cout<<ans<<endl;
  }

  return 0;
}