#include<bits/stdc++.h>
using namespace std;
int main(){
  long N;cin>>N;long x=0;
  vector<long>A(N);
  for(long i=0;i<N;i++)cin>>A[i];
  long ans=0;
  while(x!=1&&ans<=N){x=A[x]-1;ans++;}
  cout<<(ans<=N?ans:-1)<<endl;
}