#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,P;
  cin>>N>>P;
  int64_t Z=0,E=1,O=0;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    if(a%2==0){
      E*=2;
    }
    else{
      O++;
    }
  }
  int64_t Q=E;
  for(int64_t i=1;i<=O+1;i++){
    P=(P^1);
    if(P){
      Z+=Q;
    }
    Q*=O+1-i;
    Q/=i;
  }
  cout<<Z<<endl;
  
}