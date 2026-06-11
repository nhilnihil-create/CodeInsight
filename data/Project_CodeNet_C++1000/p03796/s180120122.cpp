#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  ll cnt=1,mod=1e9+7;
  for(int i=1;i<=n;i++){
    cnt*=i;
    cnt%=mod;
  }
  cout<<cnt<<endl;
}