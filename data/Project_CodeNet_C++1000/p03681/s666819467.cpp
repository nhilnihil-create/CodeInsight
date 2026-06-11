#include <bits/stdc++.h>
using namespace std;

int main() {
  int I,S;
  cin>>I>>S;
  int64_t Z=1,Q=1000000007;
  
  if(I==S){
     for(int i=1;i<=I;i++){
       Z*=i;
       Z=Z%Q;
     }
    Z*=Z;
    Z=(Z*2)%Q;
  }
  else if(I==S+1||I+1==S){
    for(int i=1;i<=min(I,S);i++){
      Z*=i;
      Z=Z%Q;
    }
    Z*=Z;
    Z=Z%Q;
    Z*=max(I,S);
    Z=Z%Q;
  }
  else{
    Z=0;
  }
  cout<<Z<<endl;
    
}