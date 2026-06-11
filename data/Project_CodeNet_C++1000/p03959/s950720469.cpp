#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;++i)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
 
const int MAX=510000;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  int n;
  cin >> n;
  vector<ll>t(n),a(n);
  rep(i,n) cin >> t[i];
  rep(i,n) cin >> a[i];
  
  vector<ll>h(n);
  
  h[0]=t[0];
  rep(i,n-1){
    if(t[i]<t[i+1])h[i+1]=t[i+1];
  }
  bool ok = true;
  if(h[n-1]!=0 && h[n-1]!=a[n-1])ok=false;
  h[n-1]=a[n-1];
  
  rep(i,n-1){
    if(a[n-1-i]<a[n-1-(i+1)] && h[n-1-(i+1)]==0)h[n-1-(i+1)]=a[n-1-(i+1)];
  }
  ll ans = 1;
  ll ma = 0;
  rep(i,n){
    if(h[i]==0){
      ans*=min(a[i],t[i]);
      ans%=MOD;
      h[i]=min(a[i],t[i]);
    }
  }
  rep(i,n){
    if(ma<h[i])ma=h[i];
    if(ma!=t[i])ok=false;
  }
  ma=0;
  rep(i,n){
    if(ma<h[n-1-i])ma=h[n-1-i];
    if(ma!=a[n-1-i])ok=false;
  }
  if(!ok)ans=0;
  cout << ans << endl;
  return 0;
}
