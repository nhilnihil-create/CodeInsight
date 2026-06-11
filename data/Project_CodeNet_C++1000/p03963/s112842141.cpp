#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
ll MM = 1000000000; ll mod = MM + 7; ll MMM=9223372036854775807;//2^63 -1
ll GCD(ll x, ll y){ if(y == 0) return x; else return GCD(y, x % y);}
ll LCM(ll x, ll y){ return x / GCD(x, y) * y;}
int dh[4] = {-1, 0, 0, 1};
int dw[4] = {0, -1, 1, 0}; 
using P = pair<int, int>;
const double pi = acos(-1.0);

using Graph = vector<vector<ll>>;

int main(){
  int n,k;
  cin>>n>>k;
  if(n==1){cout<<k<<endl;return 0;}

  ll tmp=k;
  rep(i,n-1)tmp=tmp*(k-1);
  cout<<tmp<<endl;
    
    
  return 0;
}
