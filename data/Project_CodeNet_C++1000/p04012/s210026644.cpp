#include<iostream>
#include<string>
using namespace std;

int main(){
  string w;
  cin>>w;
  
  int count[26]={0};
  for(int i=0;i<w.size();i++){
    count[w[i]-'a']++;
  }
  
  bool flag=true;
  for(int i=0;i<26;i++){
    if(count[i]%2!=0)flag=false;
  }
  
  if(flag)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
  return 0;
}