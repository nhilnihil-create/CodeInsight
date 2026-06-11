#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  string t="CODEFESTIVAL2016";
  int cnt=0;
  rep(i,s.size()){
    if(s[i]!=t[i])cnt++;
  }
  cout<<cnt<<endl;
}