#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  bool ans=true;
  rep(i,s.size())for(int j=i+1;j<s.size();j++){
    if(s[i]==s[j])ans=false;
  }
  if(ans)cout<<"yes"<<endl;
  else cout<<"no"<<endl;
}