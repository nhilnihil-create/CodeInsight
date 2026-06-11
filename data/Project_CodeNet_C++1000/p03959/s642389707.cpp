#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);++i)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
const int MOD=1e9+7;
const ll INF=1e18;
const ll inf=1e9;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
 
const int MAX=510000;

 
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  int n;
  cin >> n;
  vector<int>t(n), a(n);
  rep(i,n) cin >> t[i];
  rep(i,n) cin >> a[i];
  
  vector<int>h(n);
  h[0] = t[0];
  rep(i,n-1){
    if(t[i]<t[i+1])h[i+1]=t[i+1];
  }
  
  bool ok = true;
  if(h[n-1]!=a[n-1] && h[n-1]!=0)ok=false;
  h[n-1] = a[n-1];
  
  rep(i,n-1){
    if(a[n-1-i] < a[n-1-(i+1)] && h[n-1-(i+1)] == 0) h[n-1-(i+1)]=a[n-1-(i+1)];
  }
  ll ans = 1;
  rep(i,n-1){
    if(h[i+1]==0){
      ans *= min(t[i+1],a[i+1]);
      ans %= MOD;
      h[i+1] = min(t[i+1],a[i+1]);
    }
  }
  ll ma = t[0];
  rep(i,n-1){
    if(h[i+1]>ma)ma=h[i+1];
    if(ma!=t[i+1])ok=false;
  }
  ma = a[n-1];
  rep(i,n-1){
    if(h[n-1-(i+1)]>ma)ma=h[n-1-(i+1)];
    if(ma!=a[n-1-(i+1)])ok=false;
  }
  if(!ok)ans = 0;
  cout << ans << endl;
  
  return 0;
}
