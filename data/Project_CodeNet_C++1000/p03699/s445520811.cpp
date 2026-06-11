/**
*    author:  yuya1234
*    created: 08.07.2020 17:16:43
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

  int n;
  cin>>n;

  vector<int> v;
  int sum=0,tmp,ans=0;

  REP(i,n)
  {
    cin>>tmp;
    if(tmp%10==0)sum+=tmp;
    else v.emplace_back(tmp);
    ans+=tmp;
  }

  v.emplace_back(0);
  SORT(v);

  bool flg=false;
  REP(i,SZ(v))
  {
    ans-=v[i];
    if(ans%10!=0)
    {
      flg=true;
      break;
    }
    
  }

  if(flg)cout<<ans<<endl;
  else cout<<0<<endl;

  return 0;
}