#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef vector<pair<ll,ll> > vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>(b);--i)
const int MOD = 1000000007;
const int MAX = 510000;


int main(){
  string s;cin>>s;
  rep(i,0,5){
    cout<<s[i];
  }
  cout<<" ";
  rep(i,6,13){
    cout<<s[i];
  }
  cout<<" ";
  rep(i,14,19){
    cout<<s[i];
  }
  cout<<endl;
}


