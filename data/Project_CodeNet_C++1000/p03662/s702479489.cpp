#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define mp make_pair
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

ll n,a,b,p[100010]={},d[100010]={},s;
vector<ll> v[100010],c[100010];

void init(ll i=1,ll pe=0,ll D=0){
  p[i]=pe;d[i]=D++;
  fr(j,v[i].size()){
    if(v[i][j]!=pe){
      init(v[i][j],i,D);
      c[i].pb(v[i][j]);
    }
  }
}

ll cnt(ll i=1){
  if(i==s) return 0;
  ll e=1;
  fr(j,c[i].size()) e+=cnt(c[i][j]);
  return e;
}

int main(){
  cin>>n;
  fr(i,n-1){cin>>a>>b;v[a].pb(b);v[b].pb(a);}
  init();
  s=n;
  fr(i,(d[n]-1)/2) s=p[s];
  cout<<(cnt()>n/2?"Fennec":"Snuke")<<endl;
}