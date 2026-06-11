#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  cin>>A>>B>>C;
  bool ans=false;
  if(A==7){
    if(B==5){
      if(C==5){
        ans=true;
      }
    }
  }
  if(A==5){
    if(B==5){
      if(C==7){
        ans=true;
      }
    }
    else if(B==7){
      if(C==5){
        ans=true;
      }
    }
  }
  if(ans){
    cout<<"YES"<<endl;
  }
  else {
    cout<<"NO"<<endl;
  }
}