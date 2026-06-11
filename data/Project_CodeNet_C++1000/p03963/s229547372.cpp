#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,k;cin>>n>>k;
  int ans=k;
  k--;
  rep(i,n-1)ans*=k;
  cout<<ans<<endl;
}