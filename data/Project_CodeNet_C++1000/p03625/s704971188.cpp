//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
int main(){
  ll n;cin>>n;
  vl a(n);
  rep(i,n)cin>>a[i];
  vector<ll>ans;
  map<ll,ll>M;
  rep(i,n)M[a[i]]++;
  for(auto p:M){
    if(p.second>=4){
      ans.push_back(p.first);
      ans.push_back(p.first);
    }
    else if(p.second>=2){
      ans.push_back(p.first);
    }
  }
  sort(ans.begin(),ans.end());
  reverse(ans.begin(),ans.end());
  if(ans.size()<2){
    cout<<0<<endl;
    return 0;
  }
  cout<<ans[0]*ans[1]<<endl;
  return 0;
}
