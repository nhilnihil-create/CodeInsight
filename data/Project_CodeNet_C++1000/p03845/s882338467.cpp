#include<iostream>
#include<vector>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<int>T(N);
  int allsum=0;
  for(int i=0;i<=N-1;i++){
  
    cin>>T[i];
    allsum+=T[i];
  }
  int M;
  cin>>M;
  vector<int>P(M);
  vector<int>X(M);
  for(int i=0;i<=M-1;i++){
  
    cin>>P[i]>>X[i];
  }
  for(int i=0;i<=M-1;i++){
  
    cout<<allsum-T[P[i]-1]+X[i]<<endl;
  }
  return 0;
}