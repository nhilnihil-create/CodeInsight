#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  int n=s.size();
  int l=1e9,r=0;
  rep(i,n){
    if(s[i]=='A')l=min(l,i);
    if(s[i]=='Z')r=max(r,i);
  }
  cout<<r-l+1<<endl;
}