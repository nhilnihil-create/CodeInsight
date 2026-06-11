#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  int cnt1=1e9,cnt2=0;
  rep(i,s.size()){
    if(s[i]=='A')cnt1=min(cnt1,i+1);
    if(s[i]=='Z')cnt2=max(cnt2,i+1);
  }
  cout<<cnt2-cnt1+1<<endl;
}