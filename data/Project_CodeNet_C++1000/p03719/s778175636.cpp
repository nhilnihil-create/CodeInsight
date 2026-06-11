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
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
const int INF=INT_MAX;


int main(){
  ll a,b,c;
  cin>>a>>b>>c;
  if(c>=a&&c<=b){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
