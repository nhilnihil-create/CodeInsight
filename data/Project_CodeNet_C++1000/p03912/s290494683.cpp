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
  ll n,m;cin>>n>>m;
  vl x(n);
  rep(i,n)cin>>x[i];
  map<ll,ll>M;
  vl finished(m);
  vl all(m);
  rep(i,n)M[x[i]]++;
  for(auto p:M){
    finished[p.first%m]+=p.second/2;
    all[p.first%m]+=p.second;
  }
  ll ans=0;
  ans+=all[0]/2;
  if(m%2==0)ans+=all[m/2]/2;
  for(ll i=1;i<=(m-1)/2;i++){
    if(all[i]>=all[m-i]){
      ans+=min((all[i]-all[m-i])/2,finished[i]);
      ans+=all[m-i];
    }
    else {
      ans+=min((all[m-i]-all[i])/2,finished[m-i]);
      ans+=all[i];
    }
  }
  cout<<ans<<endl;
}