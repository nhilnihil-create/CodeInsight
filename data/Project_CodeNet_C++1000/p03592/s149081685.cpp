#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,K;
  cin>>N>>M>>K;
  bool flag=0;
  for(int i=0;i<=N;i++){
    for(int j=0;j<=M;j++){
      if((i*(M-j)+j*(N-i))==K){
        flag=1;
      }
    }
  }
  if(flag){
    cout<<"Yes"<<endl;
  }
  else cout<<"No"<<endl;
  return 0;  
}
