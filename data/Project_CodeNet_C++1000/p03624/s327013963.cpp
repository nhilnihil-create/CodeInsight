#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  vector<int> ans(26);
  rep(i,s.size()){
    ans[s[i]-'a']++;
  }
  rep(i,26){
    if(ans[i]==0){
      cout<<(char)('a'+i)<<endl;
      return 0;
    }
  }
  cout<<"None"<<endl;
}