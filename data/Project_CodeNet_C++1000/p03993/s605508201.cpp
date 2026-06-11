#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;cin>>n;
  vector<int> a(n), b(n);
  for(int i=0;i<n;++i) {
    cin>>a[i];
  }
  
  int ans = 0;
  for(int i=0;i<n;++i){
    if(a[a[i]-1]==i+1) ++ans;
  }
  cout<<ans/2<<endl;
  return 0;
}