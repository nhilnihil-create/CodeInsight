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
  
  int N,M;
  cin>>N>>M;
  
  vector<vector<char>> A(N,vector<char>(N));
  vector<vector<char>> B(M,vector<char>(M));
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>A[i][j];
    }
  }
  for(int i=0;i<M;i++){
    for(int j=0;j<M;j++){
      cin>>B[i][j];
    }
  }
  
  bool check=false;
  
  
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i+M-1>=N||j+M-1>=N){
        continue;
      }
      
      bool res=true;
      for(int k=0;k<M;k++){
        for(int l=0;l<M;l++){
          if(A[i+k][j+l]!=B[k][l]){
            res=false;
          }
        }
      }
      if(res){
        check=true;
      }
    }
  }
  
  
  if(check){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}