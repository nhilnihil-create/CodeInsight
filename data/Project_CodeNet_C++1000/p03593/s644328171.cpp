#include <bits/stdc++.h>
 
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
#define SIZE(a) ll((a).size())
#define out(a) cout<<(a)<<endl;
const ll inf=1e9;
const int MAX = 510000;
const ll MOD = 998244353;

inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

int main(){
  ll h,w;cin>>h>>w;
  vector<string> g(h);
  vll m(26,0);
  rep(i,0,h){
    cin>>g[i];
    rep(j,0,w){
      m[g[i][j]-'a']++;
    }
  }
  rep(i,0,26){
    m[i]%=4;
  }
  if(h%2==0&&w%2==0){
    rep(i,0,26){
      if(m[i]!=0){
        cout<<"No"<<endl;return 0;
      }
    }
  }
  else if(h%2&&w%2){
    ll cnt=0,c=0;
    rep(i,0,26){
      if(m[i]%2)cnt++;
      else if(m[i]!=0)c++;
    }
    if(c>(h+w-2)/2||cnt!=1){
      cout<<"No"<<endl;return 0;
    }
  }
  else{
    ll cnt=0;
    rep(i,0,26){
      if(m[i]%2){
        cout<<"No"<<endl;return 0;
      }
      else if(m[i]!=0){
        cnt++;
      }
    }
    ll t=(h%2==0?h/2:w/2);
    if(cnt>t){
      cout<<"No"<<endl;return 0;
    }
  }
  cout<<"Yes"<<endl;
}