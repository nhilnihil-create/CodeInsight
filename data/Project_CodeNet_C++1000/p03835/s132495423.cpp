#include<bits/stdc++.h>
using namespace std;

int main(){
  int K,S;
  cin >> K >> S;
  
  int cnt =0,s=S;
  for(int i=0;i<=K;i++){
    S=s;
    if(S>3*K){
      break;
    }
    S -=i;
    if(S>2*K){
      continue;
    }
    if(S>K){
      cnt +=2*K-S+1;
    }
    if(S<=K && S>=0){
      cnt +=S+1;
    }
  }
  cout << cnt <<endl;
}
