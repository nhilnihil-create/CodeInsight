#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define ft first
#define sd second
#define mp make_pair
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

ll hb(ll x){
  ll l=-1,r=32,m;
  while(r-l>1){
    m=(l+r)/2;
    if(x<(1<<m)) r=m;
    else l=m;
  }
  return r;
}

int main(){
  ll n,k,a,b,ka,k2,ans=0;
  ll s[32]={};
  vector<P> v[32];
  cin>>n>>k;
  fr(i,n){
    cin>>a>>b;
    ka=hb(a);
    v[ka].pb(mp(a,b));
    s[ka]+=b;
  }
  ifr(i,32){
    if(i==0){ans=max(ans,s[0]);break;}
    if(1-((k>>(i-1))&1)) continue;
    ka=0;
    fr(j,i) ka+=s[j];
    ans=max(ans,ka);
    ka=1<<(i-1);
    fr(j,v[i].size()){
      k2=hb(v[i][j].ft-ka);
      v[k2].pb(mp(v[i][j].ft-ka,v[i][j].sd));
      s[k2]+=v[i][j].sd;
    }
  }
  cout<<ans<<endl;
}