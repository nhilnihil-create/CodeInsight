#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  ll a,b;
  cin>>n>>a>>b;
  ll vec[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  ll ans=0;
  for(int i=0;i<n-1;i++){
    ans+=min(a*(vec[i+1]-vec[i]),b);
  }
  cout<<ans<<endl;
  return 0;
}