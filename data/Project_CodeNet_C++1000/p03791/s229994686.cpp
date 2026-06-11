#include<bits/stdc++.h>
using namespace std;
static const int64_t mod=1000000007;
int main(){
  int N;cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  int64_t ans=1;int64_t a=0;
  for(int i=0;i<N;i++){
  if(A.at(i)<=2*a){ans=(ans*(a+1))%mod;a--;}
    a++;
  }for(int64_t i=1;i<=a;i++)
    ans=(ans*i)%mod;
  cout<<ans<<endl;
  return 0;
}