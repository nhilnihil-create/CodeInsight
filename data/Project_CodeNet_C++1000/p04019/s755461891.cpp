#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  bool test1=true;
  bool test2=true;
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='N'){
      test1=false;
      for(int j=0;j<S.size();j++){
        if(S.at(j)=='S'){
          test1=true;
        }
      }
    }
    if(S.at(i)=='S'){
      test1=false;
      for(int j=0;j<S.size();j++){
        if(S.at(j)=='N'){
          test1=true;
        }
      }
    }
    if(S.at(i)=='W'){
      test2=false;
      for(int j=0;j<S.size();j++){
        if(S.at(j)=='E'){
          test2=true;
        }
      }
    }
    if(S.at(i)=='E'){
      test2=false;
      for(int j=0;j<S.size();j++){
        if(S.at(j)=='W'){
          test2=true;
        }
      }
    }
  }
  if(test1&&test2){
    cout<<"Yes"<< endl;
  }
  else{
    cout<<"No"<< endl;
  }
}
          
