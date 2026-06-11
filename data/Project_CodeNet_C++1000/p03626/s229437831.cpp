#include <bits/stdc++.h>
using namespace std;

int64_t Q=1000000007;

int main() {
  int N;
  cin>>N;
  string S,T;
  cin>>S>>T;
  int64_t A=1,Z=3,B=1;
  if(S[0]!=T[0]){
    A=2,Z=6,B=2;
  }
  while(A<N){
    if(S[A]!=T[A]){
      if(B==1){
        Z*=2;
      }
      else{
        Z*=3;
      }
      A+=2,B=2;
    }
    else{
      if(B==1){
        Z*=2;
      }
      A+=1,B=1;
    }
    Z%=Q;
  }
  cout<<Z<<endl;
}