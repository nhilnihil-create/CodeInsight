#include<bits/stdc++.h>
using namespace std;
main(){
  long n,a,b;
  cin>>n>>a>>b;
  vector<long> x(n);
  for(auto&i:x)cin>>i;
  vector<long>dist(n-1);
  for(int i=0;i<n-1;++i){
    dist[i]=x[i+1]-x[i];
  }
  long ans=0;
  for(auto d:dist){
    ans += min(d*a,b);
  }
  cout<<ans<<endl;
}