#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using datas=pair<ll,ll>;
using tdata=pair<ll,datas>;
using vec=vector<ll>;
using mat=vector<vec>;
using pvec=vector<datas>;
using pmat=vector<pvec>;
#define For(i,a,b) for(i=a;i<b;i++)
#define bFor(i,a,b) for(i=a;i>=b;i--)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define brep(i,N) bFor(i,N-1,0)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define mod 1000000007
#define endl "\n"
#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"")<<i;f=1;}cout<<endl;}while(0)

int main(){
  ll i,j,N,M,K,cnt,ans=0;
  cin>>N>>K;
  pvec v(N);
  rep(i,N){
    cin>>v[i].first>>v[i].second;
    if((v[i].first|K)==K)ans+=v[i].second;
  }
  rep(i,30){
    if(!(K&(1LL<<i)))continue;
    M=K>>(i+1)<<1;
    rep(j,i){
      M=M*2+1;
    }
    cnt=0;
    rep(j,N)if((v[j].first|M)==M)cnt+=v[j].second;
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;
  return 0;
}