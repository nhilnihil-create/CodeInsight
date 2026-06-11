#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
const int inf=1e9+7;
const ll INF=1e18;


int main() {
  int n,T;
  cin>>n>>T;
  vin t(n);
  rep(i,n) cin>>t[i];
  ///
  ll ans=0;
  rep(i,n-1){
    if(t[i+1]-t[i]>T){
      ans+=T;
    }
    else{
     ans+=t[i+1]-t[i]; 
    }
  }
  ans+=T;
  cout<<ans<<endl;
}