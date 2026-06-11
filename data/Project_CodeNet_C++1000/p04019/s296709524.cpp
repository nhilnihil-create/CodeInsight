#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int A=0,B=0,C=0,D=0;
  bool a=false;
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='N'){
      A++;
    }
    else if(S.at(i)=='W'){
      B++;
    }
    else if(S.at(i)=='S'){
      C++;
    }
    else{
      D++;
    }
  }
  if(A==0 &&C!=0){
    a=true;
  }
  else if(A!=0 && C==0){
    a=true;
  }
  else if(B==0 && D!=0){
    a=true;
  }
  else if(B!=0 && D==0){
    a=true;
  }
  if(!a){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}