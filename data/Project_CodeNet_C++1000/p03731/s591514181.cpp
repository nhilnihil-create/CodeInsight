#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N,T;
  cin>>N>>T;
  long long j=0,k=0;
  for(long long i=0;i<N;i++){
    long long t;
    cin>>t;
    j+=T-max(k-t,0LL);
    k=t+T;
  }
  cout<<j<<endl;
}