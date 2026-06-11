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
  ll k,t;cin>>k>>t;
  vll a(t);
  ll sum=0;
  rep(i,0,t){
    cin>>a[i];
    sum+=a[i];
  }
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  ll e=sum-a[0];
  if(e>a[0]){
    cout<<0<<endl;
  }
  else{
    cout<<a[0]-e-1<<endl;
  }
}






