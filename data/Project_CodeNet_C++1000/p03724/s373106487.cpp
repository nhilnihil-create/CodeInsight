//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define bit(n,k) (((ll)n>>(ll)k)&1) /*nのk bit目*/
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
//const ll MOD=1000000007LL;
const ll MOD=998244353LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};

int main(){
  ll n,m;cin>>n>>m;
  vl a(m),b(m);
  rep(i,m)cin>>a[i]>>b[i];
  map<ll,ll>M;
  rep(i,m){
    M[a[i]]++;
    M[b[i]]++;
  }
  for(auto p:M){
    if(p.second%2!=0){
      cout<<"NO"<<endl;
      return 0;
    }

  }
  cout<<"YES"<<endl;
}