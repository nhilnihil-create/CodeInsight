#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int w,a,b;cin>>w>>a>>b;
  if(abs(a-b)<=w)cout<<0<<endl;
  else cout<<abs(a-b)-w<<endl;
}