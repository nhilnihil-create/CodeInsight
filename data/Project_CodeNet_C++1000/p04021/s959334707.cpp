#include <bits/stdc++.h>
using namespace std;

signed main(){
  int n;cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  map<int,int> m;
  for(int i=0;i<n;i++)m[v[i]];
  int cnt=0;
  for(auto &p:m)p.second=cnt++;
  for(int i=0;i<n;i++)v[i]=m[v[i]];
  int ans=0;
  for(int i=0;i<n;i++)if((v[i]+i)&1)ans++;
  cout<<ans/2<<endl;
}
