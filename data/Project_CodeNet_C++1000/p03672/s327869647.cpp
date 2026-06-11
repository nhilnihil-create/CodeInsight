/**
*    author:  yuya1234
*    created: 08.07.2020 11:28:00
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

  string s;
  cin>>s;

  int ans; 
  for(int i=2;i<SZ(s);i+=2)
  {
    bool flg=true;
    REP(j,(SZ(s)-i)/2)
    {
      if(s[j]!=s[j+(SZ(s)-i)/2])flg=false;
    }
    if(flg)
    {
      ans=SZ(s)-i;
      break;
    }
  }

  cout<<ans<<endl;

  return 0;
}