#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mod 1000000007

int main(){
  string s;
  vector<string> ans;
  cin>>s;
  string temp="";
  for(int i=0;i<s.length();i++){
    if(s[i]==','){
      ans.push_back(temp);
      temp="";
    }else{
      temp=temp+s[i];
    }
  }
  ans.push_back(temp);
  
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
  return 0;
}
