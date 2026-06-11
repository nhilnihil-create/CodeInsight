#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int64_t> T(N+1),A(N+1);
  for(int i=0;i<N;++i) cin>>T[i+1]>>A[i+1];
  T[0]=1,A[0]=1;


  int64_t x=1;
  for(int i=1;i<=N;++i){
    x=max((T[i-1]*x+T[i]-1)/T[i],(A[i-1]*x+A[i]-1)/A[i]);
  }
  cout<<(A[N]+T[N])*x<<endl;
}
