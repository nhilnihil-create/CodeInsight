#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)
const ll longinf=1ll<<60;
const int inf=(1<<30)-1;

ll mod=1e9+7;

int main(){
      ll n,m;
      cin>>n>>m;
      ll x[n+1],y[m+1];
      rep1(i,n) cin>>x[i];
      rep1(j,m) cin>>y[j];
      ll s_x=0;
      ll s_y=0;
      rep1(i,n){
            s_x+=(2*i*x[i]-(n+1)*x[i]);
      }
      rep1(j,m){
            s_y+=(2*j*y[j]-(m+1)*y[j]);
      }
      s_x%=mod;
      s_y%=mod;
      cout<<(s_x*s_y)%mod<<endl;

      return 0;
}