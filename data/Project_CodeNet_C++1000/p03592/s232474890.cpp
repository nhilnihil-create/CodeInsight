#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long INF = 1LL<<60;

void YN(bool x){
  if(x) cout<<"Yes";
  else cout<<"No";
  return;
}

int main() {
  int N,H,K; cin>>N>>H>>K;
  bool finish=false;
  rep(i,N){
    if(K-i*H==0) finish=true;
    else if(i==N-i) continue;
    else{
      if(K-i*H>0 && N-i-i>0){
        if((K-i*H)%(N-i-i)==0&&(K-i*H)/(N-i-i)<=H) finish=true;
      }
      else if(K-i*H<0 && N-i-i<0){
        if((H*i-K)%(i+i-N)==0&&(H*i-K)/(i+i-N)<=H) finish=true;
      }
    }
  }
  YN(finish);   
}
