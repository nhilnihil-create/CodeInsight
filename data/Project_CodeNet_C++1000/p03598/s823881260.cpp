#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 

using namespace std;

int main() {
  int n,k;
  cin>>n>>k;
  vector<int> x(n);
  rep(i,n)cin>>x[i];
  int ans=0;
  rep(i,n){
    if(x[i]<=k-x[i])ans+=x[i]*2;
    else ans+=(k-x[i])*2;
  }
  cout<<ans<<endl;
}