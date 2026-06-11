#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  sort(s.begin(),s.end());
  string ans="yes";
  
  for(int i=0;i<s.size()-1;i++){
    if(s.at(i)==s.at(i+1)){
      ans="no";
      break;
    }
  }
  
  cout<<ans<<endl;
}