#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  string s;
  cin>>s;
  int n=s.size();
  vector<bool> vec(26);
  rep(i,n){
      vec[s[i]-'a']=true;

  }
  string ans="None";
  rep(i,26){
      if(vec[i]==false){
          ans='a'+i;
          break;
      }
  }
  cout<<ans<<endl;
}