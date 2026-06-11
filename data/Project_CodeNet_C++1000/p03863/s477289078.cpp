#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int n=s.length();
  int flag=0;
  if(s.at(0)==s.at(n-1)){
    if(n%2 ==0){
      flag=1;
    }
    else{
      flag=2;
    }
  }
  else{
    if(n%2 ==0){
      flag=2;
    }
    else{
      flag=1;
    }
  }
  if(flag==1){
    cout<<"First"<<endl;
    return 0;
  }
  else{
    cout<<"Second"<<endl;
    return 0;
  }
}
