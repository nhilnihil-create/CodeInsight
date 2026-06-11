#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M,K,n,m;cin>>N>>M>>K;
  for(n=0;n<=N;n++){
    for(m=0;m<=M;m++){
      if(N*m+M*n-2*m*n==K)break;
    }
    if(m!=M+1)break;
  }
  if(n!=N+1)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}