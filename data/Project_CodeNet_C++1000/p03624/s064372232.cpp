#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  string s;cin>>s;
  vector<bool> vec(26);
  rep(i,26)vec[i]=false;
  rep(i,s.size()){
    vec[s[i]-'a']=true;
  }
  rep(i,26){
    if(vec[i])continue;
    else {
      cout<<(char)(i+'a')<<endl;
      return 0;
    }
  }
  cout<<"None"<<endl;
}