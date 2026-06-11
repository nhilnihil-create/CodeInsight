#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int A,B;cin>>A>>B;
  
  if(A==B){
    cout<<"Draw"<<endl;
  }
  else{
    if(A!=1&&B!=1){
      if(A<B){
        cout<<"Bob"<<endl;
      }
      else{
        cout<<"Alice"<<endl;
      }
    }
    else if(A==1&&B!=1){
      cout<<"Alice"<<endl;
    }
    else{
      cout<<"Bob"<<endl;
    }
  }
}