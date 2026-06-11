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
const ll MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

int main(){
  ll sx,sy,tx,ty;cin>>sx>>sy>>tx>>ty;
  ll x=tx-sx,y=ty-sy;
  rep(i,0,y){
    cout<<'U';
  }
  rep(i,0,x){
    cout<<'R';
  }
  rep(i,0,y){
    cout<<'D';
  }
  rep(i,0,x){
    cout<<'L';
  }
  
  cout<<'L';
  
  rep(i,0,y+1){
    cout<<'U';
  }
  rep(i,0,x+1){
    cout<<'R';
  }
  cout<<'D'<<'R';
  
  rep(i,0,y+1){
    cout<<'D';
  }
  rep(i,0,x+1){
    cout<<'L';
  }
  cout<<'U'<<endl;
}

