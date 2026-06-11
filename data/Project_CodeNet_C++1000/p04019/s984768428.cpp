#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  bool n1=false,w1=false,s1=false,e1=false;
  for(int i=0;i<s.size();i++){
    if(s[i]=='N'){
      n1=true;
    }else if(s[i]=='W'){
      w1=true;
    }else if(s[i]=='S'){
      s1=true;
    }else{
      e1=true;
    }
  }
  if((n1!=s1) || (w1!=e1)){
    cout<<"No"<<endl;
  }else{
    cout<<"Yes"<<endl;
  }
}