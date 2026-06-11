#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string a,b;cin>>a>>b;
  int c=a.size(),d=b.size();
  if(c-d==1){
    rep(i,d)cout<<a[i]<<b[i];
    cout<<a[c-1]<<endl;
  }
  else {
    rep(i,c)cout<<a[i]<<b[i];
    cout<<endl;
  }
}