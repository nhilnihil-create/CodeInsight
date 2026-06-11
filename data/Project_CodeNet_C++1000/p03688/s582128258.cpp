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
  ll n;cin>>n;
  vl a(n);
  rep(i,n)cin>>a[i];
  sort(a.begin(),a.end());
  map<ll,ll>M;
  rep(i,n)M[a[i]]++;
  if(M.size()==1){
    if((M[a.front()]>=a.front()*2)||(M[a.front()]==a.front()+1)){
      cout<<"Yes"<<endl;
      //cout<<"ok"<<endl;
      return 0;
    }
  }
  else if(a.back()-a.front()==1){
    if(M[a.front()]<=a.front()&&M[a.back()]>=(a.back()-M[a.front()])*2){
      cout<<"Yes"<<endl;
      return 0;
    }

  }
  cout<<"No"<<endl;
}