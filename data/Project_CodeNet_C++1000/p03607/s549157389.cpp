/**
*    author:  yuya1234
*    created: 09.07.2020 09:46:09
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
  int tmp;
  REP(i,n)
  {
    cin>>tmp;
    v.emplace_back(tmp);
  }

  SORT(v);

  int cnt=1,ans=0;
  REP(i,n-1)
  {
    if(v[i]==v[i+1])cnt++;
    else
    {
      if(cnt%2!=0)ans++;
      cnt=1;
    }
  }

  if(cnt%2!=0)ans++;

  cout<<ans<<endl;

  return 0;
}