#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int main(){
  string s;
  char ab='a';
  cin>>s;
  map<char,int> ans;
  for(int i=0;i<s.length();++i){
    ++ans[s[i]];
  }
  if(ans.size()==26){
    cout<<"None"<<endl;
    return 0;
  }
  for(int i=0;i<s.length();++i){
    if(ans[ab]==0){
      cout<<ab<<endl;
      return 0;
    }
    ++ab;
  }//*/
}