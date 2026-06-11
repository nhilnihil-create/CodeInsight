#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> l(2*n);
  rep(i,2*n)cin>>l[i];
  sort(all(l));
  int ans=0;
  for(int i=0;i<2*n;i+=2){
    ans+=min(l[i],l[i+1]);
  }
  cout<<ans<<endl;
}