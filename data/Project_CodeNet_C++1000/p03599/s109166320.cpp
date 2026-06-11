//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
  vector<ll>vec;
  rep(i,3001){
    rep(j,1500){
      vec.push_back(c*i+d*j);
    }
  }
  double ans=-1;
  ll anssugar;
  ll answater;
  sort(vec.begin(),vec.end());
  for(ll i=0;100*i*a<=f;i++){
    for(ll j=0;100*i*a+100*j*b<=f;j++){
      ll remain=min(e*(a*i+b*j),f-100*(a*i+b*j));
      ll water=100*(a*i+b*j);
      ll idx_upper=distance(vec.begin(),upper_bound(vec.begin(),vec.end(),remain));
      idx_upper--;
      double sugar=vec[idx_upper];
      if(sugar+water>0&&ans<sugar/(sugar+water)){
        ans=sugar/(sugar+water);
        anssugar=sugar;
        answater=water;
      }
    }
  }
  cout<<anssugar+answater<<" "<<anssugar<<endl;
}