#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int h,w;cin>>h>>w;
  vector<string> s(h);
  rep(i,h)cin>>s[i];
  rep(i,w+2)cout<<'#';
  cout<<endl;
  rep(i,h){
    cout<<'#'<<s[i]<<'#';
  cout<<endl;
          }
   rep(i,w+2)cout<<'#';
  cout<<endl;
}