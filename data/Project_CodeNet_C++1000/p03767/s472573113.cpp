#include<bits/stdc++.h>
using namespace std;
#define int int64_t
signed main(){
  int n;
  cin>>n;
  vector<int> x(n*3);
  for(auto &&i : x) cin>>i;
  sort(x.begin(),x.end(),greater<int>());
  int ans = 0;
  for(int i=0;i<n;++i) ans += x[i*2+1];
  cout<<ans<<'\n';
  return 0;
}
