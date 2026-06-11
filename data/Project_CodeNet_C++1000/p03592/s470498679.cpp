#include <bits/stdc++.h>
using namespace std;


int main() {
  int N,M,K;
  cin>>N>>M>>K;
  bool flg=0;
  for(int i=0;i<=N;i++){
      for(int j=0;j<=M;j++){
        //cout<<M*i+N*j-i*j*2<<endl;
        if(M*i+N*j-i*j*2==K) flg=1;
      }
  }
  if(flg) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
