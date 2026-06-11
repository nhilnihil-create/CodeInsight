#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int h=0;
  int w=0;
  for(int i=0;i<s.size();i++){
    if(s[i]=='N'){
      h++;
      break;
    }
  }
  for(int i=0;i<s.size();i++){
    if(s[i]=='W'){
      w++;
      break;
    }
  }for(int i=0;i<s.size();i++){
    if(s[i]=='S'){
      h++;
      break;
    }
  }for(int i=0;i<s.size();i++){
    if(s[i]=='E'){
      w++;
      break;
    }
  }
  if(h%2==0&&w%2==0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}