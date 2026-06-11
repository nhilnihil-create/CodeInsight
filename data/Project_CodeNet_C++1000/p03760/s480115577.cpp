#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string a,b;cin>>a>>b;
  if(a.size()==b.size()){
    rep(i,a.size())cout<<a[i]<<b[i];
    cout<<endl;
  }
  else {
    rep(i,b.size())cout<<a[i]<<b[i];
    cout<<a[a.size()-1]<<endl;
  }
}