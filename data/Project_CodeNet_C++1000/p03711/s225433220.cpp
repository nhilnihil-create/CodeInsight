#include <bits/stdc++.h>
using namespace std;

int main(){
  bool A=false;
  bool B=false;
  bool C=true;
  int a,b;
  cin >> a >> b;
  vector<int>N(7);
  N.at(0)=1;
  N.at(1)=3;
  N.at(2)=5;
  N.at(3)=7;
  N.at(4)=8;
  N.at(5)=10;
  N.at(6)=12;
  vector<int>M(4);
  M.at(0)=4;
  M.at(1)=6;
  M.at(2)=9;
  M.at(3)=11;
  for(int i=0;i<7;i++){
    if(N.at(i)==a){
      A=true;
      C=false;
    }
    if(N.at(i)==b){
      B=true;
      C=false;
    }
  }
  if(C==true){
    for(int i=0;i<4;i++){
      if(M.at(i)==a){
        A=true;
        C=false;
      }
      if(M.at(i)==b){
        B=true;
        C=false;
      }
    }
  }
  if(A&&B){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
