#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int64_t A=0,B=0;
  cin>>N;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    cin>>p.at(i);
  }
  int Z=0;
  for(int i=0;i<N;i++){
    Z+=p.at(i);
    if(i%2==0){
      if(Z>=0){
        A+=1+Z;
        Z=-1;
      }
    }
    else{
      if(Z<=0){
        A+=1-Z;
        Z=1;
      }
    }
  }
  Z=0;
  for(int i=0;i<N;i++){
    Z+=p.at(i);
    if(i%2==1){
      if(Z>=0){
        B+=1+Z;
        Z=-1;
      }
    }
    else{
      if(Z<=0){
        B+=1-Z;
        Z=1;
      }
    }
  }
  cout<<min(A,B)<<endl;
                
}