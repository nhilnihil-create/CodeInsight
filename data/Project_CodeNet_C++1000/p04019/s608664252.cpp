#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;cin>>S;
  vector<int>mark(4);
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='N'){
      mark.at(0)=1;
    }
    if(S.at(i)=='S'){
      mark.at(1)=1;
    }
    if(S.at(i)=='W'){
      mark.at(2)=1;
    }
    if(S.at(i)=='E'){
      mark.at(3)=1;
    }
  }
  bool flag=true;
  if(mark.at(0)!=mark.at(1)){
    flag=false;
  }
  if(mark.at(2)!=mark.at(3)){
    flag=false;
  }
  if(flag){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
  
    
