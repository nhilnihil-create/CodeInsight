#include<bits/stdc++.h>
using namespace std;

int main(){
  
  long long N, M;
  cin >> N >> M;
  
  if(M<N*2){
    cout << M/2 << endl;
  }else{
    M = M-2*N;
    cout << N+M/4 << endl;
  }
  return 0;
}