#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  vector<int>vec(26);
  rep(i,s.size()){
    vec[s[i]-'a']++;
  }
  rep(i,26){
    if(vec[i]%2==1){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}
