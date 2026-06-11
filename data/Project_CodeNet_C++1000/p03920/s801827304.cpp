#include <bits/stdc++.h>
using namespace std;

int main() {
  long N,M;
  cin>>N;
  for(int i=0;i<=N;i++){
    if(i*(i+1)/2>=N){
      M=i;
      break;
    }
  }
  for(int i=1;i<=M;i++){
    if(i==M*(M+1)/2-N){
      continue;
    }
    cout<<i<<endl;
  }
  
  
}