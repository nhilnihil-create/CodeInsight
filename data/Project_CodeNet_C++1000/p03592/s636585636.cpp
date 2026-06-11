#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, M, K;
  cin >> N >> M >> K;
  for(int i=0; i<=N; i++){
    for(int j=0; j<=M; j++){
      if(i*M+j*N-2*i*j==K){
        cout << "Yes" << endl;
        goto finish;
      }
    }
  }
  cout << "No" << endl;
  finish: N=0;
}