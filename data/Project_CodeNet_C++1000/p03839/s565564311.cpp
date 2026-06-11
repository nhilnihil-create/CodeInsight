#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,K;
  cin>>N>>K;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  vector<int64_t>B(N);
  int64_t b=0;
  for(int i=0;i<N;i++){
  if(0<=A.at(i))b+=A.at(i);
    B.at(i)=b;
  }vector<int64_t>C(N-K+1);
  int64_t c=0;
  for(int i=0;i<K;i++)
    c+=A.at(i);
  C.at(0)=c;
  for(int i=1;i<=N-K;i++)
    C.at(i)=C.at(i-1)-A.at(i-1)+A.at(K+i-1);
  int64_t ans=0;
  for(int i=0;i<=N-K;i++){
  int64_t d=B[N-1]-B[K+i-1];
    if(0<=C[i])d+=C[i];
    if(0<=i-1)d+=B[i-1];
    if(ans<d)
      ans=d;
  }cout<<ans<<endl;
  return 0;
}