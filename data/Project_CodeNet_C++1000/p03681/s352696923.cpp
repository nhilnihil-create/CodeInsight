#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N,M;
  cin>>N>>M;
  if(abs(N-M)>1){
    cout<<0<<endl;
    return 0;
  }
  long long j=1;
  for(long long i=1;i<=N;i++)
    j=j*i%1000000007;
  for(long long i=1;i<=M;i++)
    j=j*i%1000000007;
  if(N==M)
    cout<<j*2%1000000007<<endl;
  else
    cout<<j<<endl;
}