#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}

int main(){
  ll n;
  cin>>n;
  vector<ll>a(n);
  vector<ll>b(n);
  rep(i,n){cin>>a[i]>>b[i];}
  

  ll ans=0;
  rep(i,n){

    if((a[n-1-i]+ans)%b[n-1-i]==0)continue;
    else ans=ans+b[n-i-1]-((a[n-1-i]+ans)%b[n-1-i]);
    
    
  }
  cout<<ans<<endl; 
    
  return 0;
}
