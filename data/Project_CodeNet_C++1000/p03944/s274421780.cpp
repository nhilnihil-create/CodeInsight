#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
long long GCD(long long A,long long B){
  if(B==0){
    return A;
  }
  else{
    return GCD(B,A%B);
  }
}
int main() {
  
  int W,H,N;
  cin>>W>>H>>N;
  
  vector<vector<int>> vec(N,vector<int>(3));
  for(int i=0;i<N;i++){
    cin>>vec[i][0]>>vec[i][1]>>vec[i][2];
  }
  
  int X=0;
  int Y=0;
  
  
  for(int i=0;i<N;i++){
    if(vec[i][2]==1){
      X=max(X,vec[i][0]);
    }
    else if(vec[i][2]==2){
      W=min(W,vec[i][0]);
    }
    else if(vec[i][2]==3){
      Y=max(Y,vec[i][1]);
    }
    else{
      H=min(H,vec[i][1]);
    }
  }
  
  cout<<max(0,W-X)*max(0,H-Y)<<endl;
}