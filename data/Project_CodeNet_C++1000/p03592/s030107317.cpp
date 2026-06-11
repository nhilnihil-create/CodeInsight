#include<bits/stdc++.h>
using namespace std;
int main(){
int N,M,K;
  cin>>N>>M>>K;
  bool x=false;
  for(int i=0;i<=N;i++){
  for(int j=0;j<=M;j++){
  if(i*(M-j)+j*(N-i)==K){x=true; break;}
  }
  }if(x)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
    return 0;
}