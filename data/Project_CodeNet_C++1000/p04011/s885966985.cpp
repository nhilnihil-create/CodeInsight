#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,K,X,Y,sum=0;
  cin >> N >> K >> X >> Y;
  if(K<N){
    for(int i=1;i<=K;i++){
      sum+=X;
    }
    for(int i=K+1;i<=N;i++){
      sum+=Y;
    }
  }
  else{
    sum=X*N;
  }
  cout << sum << endl;
}
    