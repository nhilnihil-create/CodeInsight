#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  string s;
  cin>>s;
  vector<int> vec(26,0);
  rep(i,s.size()){
    vec[s[i]-'a']++;
  }
  string ans="Yes";
  rep(i,26){
    if(vec[i]%2!=0){
      ans="No";
    }
  }
  cout<<ans<<endl;
}