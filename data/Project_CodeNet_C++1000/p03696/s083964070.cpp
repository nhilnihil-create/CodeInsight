#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef vector<pair<ll,ll> > vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
const int MOD = 1000000007;
const int MAX = 510000;


int main(){
  ll x,sum=0,tmp=0;cin>>x;
  string s;
  rep(i,0,x){
    cin>>s[i];
    if(s[i]=='('){
      sum++;
    }
    else{
      if(sum>0){sum--;}
      else{tmp++;}
    }
  }
  rep(i,0,tmp){cout<<'(';}
  rep(i,0,x){cout<<s[i];}
  rep(i,0,sum){cout<<')';}
  cout<<endl;
}

