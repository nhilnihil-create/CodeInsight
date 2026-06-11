#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> t(n);
  rep(i,n)cin>>t[i];
  int m;cin>>m;
  rep(i,m){
    int p,x;cin>>p>>x;
    int cnt=0;
    rep(j,n){
      if(j+1==p)cnt+=x;
      else cnt+=t[j];
    }
    cout<<cnt<<endl;
  }
}