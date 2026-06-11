#include<bits/stdc++.h>
using namespace std;
#define int long
signed main(){
  int n;
  cin>>n;
  vector<int> p(n),q(n),a(n),b(n);
  for(auto& i:p)cin>>i,--i;
  for(int i=0;i<n;++i)q[p[i]]=i;
  for(int i=1;i<=n;++i)a[i-1]=b[n-i]=i*(1e9/2e4-10);
  for(int i=0;i<n;++i)cout<<(i?" ":"")<<a[i];
  cout<<"\n";
  for(int i=0;i<n;++i)cout<<(i?" ":"")<<b[i]+q[i];
}