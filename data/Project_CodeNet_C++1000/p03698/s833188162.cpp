#include<iostream>
#include<map>
#include<string>

using namespace std;
int main(){
  string s;
  cin>>s;
  map<char,int> a;
  for(int i=0;i<s.size();++i){
    ++a[s[i]];
    if(a[s[i]]>1){
      cout<<"no"<<endl;
      return 0;
    }
  }
  cout<<"yes"<<endl;
  return 0;
}