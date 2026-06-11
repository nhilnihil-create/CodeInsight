#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> t(n);
  int cnt=0;
  rep(i,n){
    cin>>t[i];
    cnt+=t[i];
  }
  int m;cin>>m;
  rep(i,m){
    int p,x;cin>>p>>x;
    int ans=cnt+x-t[p-1];
    cout<<ans<<endl;
  }
}