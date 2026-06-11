#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1L<<32;
ll fac[MAX], finv[MAX], inv[MAX];
//ワーシャルフロイド法、o(v^3)
int main(){
  ll v,e,r,ans=MOD;cin>>v>>e>>r;
  vll rr(r);
  rep(i,0,r){cin>>rr[i];rr[i]--;}
  vvll g(v,vll(v,MOD));
  rep(i,0,e){
    ll s,t,d;cin>>s>>t>>d;
    s--;t--;
    g[s][t]=d;
    g[t][s]=d;
  }
  rep(i,0,v){g[i][i]=0;}
  
  rep(k,0,v){
    rep(i,0,v){
      rep(j,0,v){
        g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
      }
    }
  }
  sort(rr.begin(),rr.end());
  do{
    ll tmp=0;
    rep(i,0,r-1){
      tmp+=g[rr[i]][rr[i+1]];
    }
    ans=min(ans,tmp);
  }while(next_permutation(rr.begin(),rr.end()));
  
  out(ans);
}


