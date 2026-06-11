#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)j; i<(int)n; i++)
int main() {
  int n,m; cin>>n;
  int t[n]; rep(i,0,n) cin>>t[i];
  cin>>m;
  int p[m],x[m]; rep(i,0,m) cin>>p[i]>>x[i];
  rep(i,0,m){
    int ans=0;
    rep(j,0,n){
      if(p[i]-1==j) ans+=x[i];
      else ans+=t[j];
    }
    cout<<ans<<endl;
  }
}