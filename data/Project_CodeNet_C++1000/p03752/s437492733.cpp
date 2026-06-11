#include<bits/stdc++.h>
using namespace std;
int main(){
  long N,K;cin>>N>>K;
  vector<long>A(N);
  long ans=LONG_MAX;
  for(long i=0;i<N;i++)cin>>A[i];
  for(long i=0;i<(1<<N);i++){
    bitset<15>b(i);
    if(b.count()<K)continue;
    long M=0,s=0;
    
    for(long j=0;j<N;j++){
      if(b[j]){
        if(M>=A[j]){
          s+=M-A[j]+1;
          M=max(M+1,A[j]);
        }
      }
      M=max(M,A[j]);
    }
    ans=min(ans,s);
    
  }
  cout<<ans<<endl;
}