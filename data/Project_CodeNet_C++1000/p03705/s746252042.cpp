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

int main(){
  ll n,a,b;cin>>n>>a>>b;
  if(b<a){cout<<0<<endl;return 0;}
  if(n==1&&a!=b){cout<<0<<endl;return 0;}
  ll l=(n-1)*a+b,r=(n-1)*b+a;
  cout<<r-l+1<<endl;
}
