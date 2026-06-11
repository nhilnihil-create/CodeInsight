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
  for(int i=0;i<=N;i++) for(int j=0;j<=H;j++) if(i*H+j*N-2*i*j==K) finish=true;
  YN(finish);   
}
