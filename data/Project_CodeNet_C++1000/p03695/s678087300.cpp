/**
*    author:  yuya1234
*    created: 08.07.2020 13:35:30
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

  int tmp;
  int a[9];
  MEMSET(a,0);

  REP(i,n)
  {
    cin>>tmp;
    if(tmp<400)a[0]=1;
    else if(tmp<800)a[1]=1;
    else if(tmp<1200)a[2]=1;
    else if(tmp<1600)a[3]=1;
    else if(tmp<2000)a[4]=1;
    else if(tmp<2400)a[5]=1;
    else if(tmp<2800)a[6]=1;
    else if(tmp<3200)a[7]=1;
    else a[8]++;
  }

  int cnt=0,amax=0,amin=0;

  REP(i,8)
  {
    if(a[i]==1)cnt++;
  }

  if(a[8]==0)
  {
    amax=amin=cnt;
  }
  else
  {
    if(cnt==0)
    {
      amax=a[8];
      amin=1;
    }
    else
    {
      amax=cnt+a[8];
      amin=cnt;
    }
    
  }

  cout<<amin<<" "<<amax<<endl;
  

  return 0;
}