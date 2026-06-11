#include <bits/stdc++.h>
using namespace std;
int main(){
  long long Q,H,S,D,N; cin>>Q>>H>>S>>D>>N;
  cout<<min(min(min(min(min(Q*4*N,H*2*N),S*N),D*(N/2)+S*(N%2)),D*(N/2)+H*(N%2)*2),D*(N/2)+(N%2)*4*Q)<<endl;
}